#!/usr/bin/env bash
set -euo pipefail

print_help() {
  cat <<'EOF'
Usage:
  ./build.sh <source-file>
  ./build.sh -h(--help)

Description:
  Compile one C/C++ source file and run the generated executable.

Supported extensions:
  .cpp, .cc, .cxx, .c++  Compiled with /opt/homebrew/bin/g++-15
  .c                     Compiled with gcc

Output:
  Executables are created under build/ with this format:
  build/<filename>_YYYYMMDD_HHMMSS

Input file:
  If a matching .in file exists next to the source file, it is used as stdin.

Examples:
  ./build.sh base/base_code.cpp
  ./build.sh labs/lab5.cpp
EOF
}

if [ "$#" -eq 1 ] && { [ "$1" = "-h" ] || [ "$1" = "--help" ]; }; then
  print_help
  exit 0
fi

if [ "$#" -ne 1 ]; then
  print_help
  exit 1
fi

source_file="$1"

if [ ! -f "$source_file" ]; then
  echo "Source file not found: $source_file"
  exit 1
fi

extension="${source_file##*.}"
filename="$(basename "$source_file")"
name_without_extension="${filename%.*}"
timestamp="$(date +"%Y%m%d_%H%M%S")"
build_dir="build"
output_file="$build_dir/${name_without_extension}_${timestamp}"
input_file="${source_file%.*}.in"
cxx_compiler="/opt/homebrew/bin/g++-15"

mkdir -p "$build_dir"

case "$extension" in
  cpp|cc|cxx|c++)
    if [ ! -x "$cxx_compiler" ]; then
      echo "C++ compiler not found: $cxx_compiler"
      exit 1
    fi
    "$cxx_compiler" -std=c++17 -Wall -Wextra -O2 "$source_file" -o "$output_file"
    ;;
  c)
    gcc -Wall -Wextra -O2 "$source_file" -o "$output_file"
    ;;
  *)
    echo "Unsupported source extension: .$extension"
    exit 1
    ;;
esac

echo "Built: $output_file"

if [ -f "$input_file" ]; then
  echo "Running with input: $input_file"
  "$output_file" < "$input_file"
else
  echo "Running without input file"
  "$output_file"
fi
