# C++ 코딩 테스트 암기 연습

원본 코드를 눈으로만 읽지 않고 직접 반복해서 작성하며 문법과 알고리즘 패턴을 익히는 공간입니다.

## 디렉터리

```text
coding-test-memory/
├── reference/    # 수정하지 않고 참고하는 원본 코드
├── practice/     # 직접 작성한 연습 코드
└── progress.md   # 반복 학습 진도
```

`practice/`의 연습 코드는 개인 로컬 학습용이라 Git에 포함하지 않습니다. Git에는 빈 디렉터리를 유지하기 위한 `practice/.gitkeep`만 저장합니다.

`reference/`와 `practice/`는 같은 주제 이름을 사용합니다. 예를 들어 원본이
`reference/00_basic/01_pointer_reference.cpp`라면 연습 코드는 다음 위치에 저장합니다.

```text
practice/00_basic/01_pointer_reference/attempt_01.cpp
practice/00_basic/01_pointer_reference/attempt_02.cpp
practice/00_basic/01_pointer_reference/attempt_03.cpp
```

## 연습 방법

1. 원본과 주석을 읽고 `attempt_01.cpp`에 직접 작성합니다.
2. 원본을 닫고 `attempt_02.cpp`에 핵심 로직을 다시 작성합니다.
3. 변수명과 예제 입력을 바꿔 `attempt_03.cpp`에 작성합니다.
4. 다음 날 빈 파일에서 5분 안에 다시 작성합니다.
5. `progress.md`에서 완료한 단계를 갱신합니다.

연습 파일은 저장소 루트의 빌드 스크립트로 실행할 수 있습니다.

```bash
./build.sh coding-test-memory/practice/00_basic/01_pointer_reference/attempt_01.cpp
```

원본 코드의 오타나 오류를 발견한 경우를 제외하면 `reference/`는 수정하지 않습니다. 연습하며 알게 된 내용은 해당 연습 디렉터리의 `notes.md`에 기록합니다.

## 파일 이름 규칙

- 반복 작성: `attempt_01.cpp`, `attempt_02.cpp`, ...
- 개인 메모: `notes.md`
- 예제 입력: `attempt_01.in`, `attempt_02.in`, ...

숫자는 작성 순서를 나타내며, 기존 파일을 덮어쓰지 않고 새 시도로 남깁니다.

## 연습 파일 한꺼번에 만들기

`new-attempt.sh`는 `reference/`의 모든 C++ 파일을 읽어 같은 분류와 주제 이름으로 빈 연습 파일을 만듭니다.

```bash
# 모든 주제의 attempt_01.cpp 만들기
./coding-test-memory/new-attempt.sh

# 모든 주제의 attempt_02.cpp 만들기
./coding-test-memory/new-attempt.sh 2

# 05_graph 아래 모든 주제의 attempt_03.cpp 만들기
./coding-test-memory/new-attempt.sh dir 05_graph 3

# BFS 주제에서 현재 마지막 회차의 다음 파일 하나 만들기
./coding-test-memory/new-attempt.sh file 05_graph/03_bfs.cpp

# coding-test-memory 디렉터리 안에서는 reference/ 경로를 직접 전달해도 됨
./new-attempt.sh file ./reference/05_graph/03_bfs.cpp
```

`dir`과 `file` 뒤에는 `reference/` 기준 경로 또는 실제 `reference/` 경로를 입력할 수 있습니다. `file` 명령은 해당 주제에 있는 `attempt_*.cpp` 중 가장 큰 번호를 찾아 그다음 회차를 생성합니다.

이미 존재하는 연습 파일은 건너뛰므로 작성한 코드가 비워지거나 덮어써지지 않습니다. 시도 번호는 1 이상의 정수로 입력합니다.
