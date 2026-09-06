#!/usr/bin/env sh

set -eu

SCRIPT_DIR=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
REFERENCE_DIR="$SCRIPT_DIR/reference"
PRACTICE_DIR="$SCRIPT_DIR/practice"

usage() {
    cat <<EOF
사용법:
  $0 [시도 번호]
  $0 all [시도 번호]
  $0 dir <reference 기준 디렉터리> <시도 번호>
  $0 file <reference 기준 C++ 파일>

예시:
  $0 2
  $0 dir 05_graph 3
  $0 file 05_graph/03_bfs.cpp
  $0 file ./reference/05_graph/03_bfs.cpp
EOF
}

reference_candidate_for() {
    requested=$1

    # 현재 작업 디렉터리를 기준으로 실제 경로가 존재하면 그대로 사용한다.
    if [ -e "$requested" ]; then
        printf '%s\n' "$requested"
        return
    fi

    # 그 외에는 스크립트 위치와 reference/를 기준으로 해석한다.
    case "$requested" in
        /*) printf '%s\n' "$requested" ;;
        ./reference/*) printf '%s\n' "$SCRIPT_DIR/${requested#./}" ;;
        reference/*) printf '%s\n' "$SCRIPT_DIR/$requested" ;;
        ./*) printf '%s\n' "$REFERENCE_DIR/${requested#./}" ;;
        *) printf '%s\n' "$REFERENCE_DIR/$requested" ;;
    esac
}

validate_attempt_number() {
    case "$1" in
        ''|*[!0-9]*)
            echo "시도 번호는 1 이상의 정수여야 합니다: $1" >&2
            exit 1
            ;;
    esac

    if [ "$1" -lt 1 ]; then
        echo "시도 번호는 1 이상이어야 합니다." >&2
        exit 1
    fi
}

resolve_reference_directory() {
    requested=$1
    candidate=$(reference_candidate_for "$requested")

    if [ ! -d "$candidate" ]; then
        echo "reference 디렉터리를 찾을 수 없습니다: $requested" >&2
        exit 1
    fi

    resolved=$(CDPATH= cd -- "$candidate" && pwd)
    case "$resolved/" in
        "$REFERENCE_DIR"/*) printf '%s\n' "$resolved" ;;
        *)
            echo "reference 밖의 디렉터리는 사용할 수 없습니다: $requested" >&2
            exit 1
            ;;
    esac
}

resolve_reference_file() {
    requested=$1
    candidate=$(reference_candidate_for "$requested")

    if [ ! -f "$candidate" ]; then
        echo "reference C++ 파일을 찾을 수 없습니다: $requested" >&2
        exit 1
    fi

    case "$candidate" in
        *.cpp) ;;
        *)
            echo "C++ 파일만 사용할 수 있습니다: $requested" >&2
            exit 1
            ;;
    esac

    resolved_directory=$(CDPATH= cd -- "$(dirname -- "$candidate")" && pwd)
    resolved="$resolved_directory/$(basename -- "$candidate")"
    case "$resolved" in
        "$REFERENCE_DIR"/*) printf '%s\n' "$resolved" ;;
        *)
            echo "reference 밖의 파일은 사용할 수 없습니다: $requested" >&2
            exit 1
            ;;
    esac
}

practice_directory_for() {
    reference_file=$1
    relative_path=${reference_file#"$REFERENCE_DIR"/}
    category_path=${relative_path%/*}
    file_name=${relative_path##*/}
    topic=${file_name%.cpp}
    printf '%s\n' "$PRACTICE_DIR/$category_path/$topic"
}

create_attempt() {
    reference_file=$1
    attempt_number=$2
    target_dir=$(practice_directory_for "$reference_file")
    attempt_name=$(printf 'attempt_%02d.cpp' "$attempt_number")
    target_file="$target_dir/$attempt_name"

    mkdir -p "$target_dir"

    if [ -e "$target_file" ]; then
        echo "건너뜀: ${target_file#"$SCRIPT_DIR"/}"
    else
        : > "$target_file"
        echo "생성: ${target_file#"$SCRIPT_DIR"/}"
    fi
}

create_for_directory() {
    source_dir=$1
    attempt_number=$2

    find "$source_dir" -type f -name '*.cpp' | sort | while IFS= read -r reference_file; do
        create_attempt "$reference_file" "$attempt_number"
    done
}

create_next_for_file() {
    reference_file=$1
    target_dir=$(practice_directory_for "$reference_file")
    mkdir -p "$target_dir"

    next_number=$(
        find "$target_dir" -maxdepth 1 -type f -name 'attempt_*.cpp' \
            | sed -n 's#^.*/attempt_\([0-9][0-9]*\)\.cpp$#\1#p' \
            | awk 'BEGIN { max = 0 } { value = $1 + 0; if (value > max) max = value } END { print max + 1 }'
    )

    create_attempt "$reference_file" "$next_number"
}

if [ ! -d "$REFERENCE_DIR" ]; then
    echo "reference 디렉터리를 찾을 수 없습니다: $REFERENCE_DIR" >&2
    exit 1
fi

case ${1:-all} in
    all)
        if [ "$#" -gt 2 ]; then usage >&2; exit 1; fi
        attempt_number=${2:-1}
        validate_attempt_number "$attempt_number"
        create_for_directory "$REFERENCE_DIR" "$attempt_number"
        ;;
    dir)
        if [ "$#" -ne 3 ]; then usage >&2; exit 1; fi
        source_dir=$(resolve_reference_directory "$2")
        validate_attempt_number "$3"
        create_for_directory "$source_dir" "$3"
        ;;
    file)
        if [ "$#" -ne 2 ]; then usage >&2; exit 1; fi
        reference_file=$(resolve_reference_file "$2")
        create_next_for_file "$reference_file"
        ;;
    -h|--help|help)
        usage
        ;;
    *)
        if [ "$#" -ne 1 ]; then usage >&2; exit 1; fi
        validate_attempt_number "$1"
        create_for_directory "$REFERENCE_DIR" "$1"
        ;;
esac
