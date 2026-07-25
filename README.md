### 알고리즘 공부 후 저장한 소스코드를 저장하기 위한 레포지토리입니다.

## 빌드 및 실행

`build.sh`에 소스 파일 경로를 넘기면 컴파일 후 바로 실행됩니다.

```bash
./build.sh base/base_code.cpp
./build.sh baekjoon/1026.cpp
```

실행 파일은 `build/파일명_YYYYMMDD_HHMMSS` 형식으로 생성됩니다.

소스 파일과 같은 위치에 같은 이름의 `.in` 파일이 있으면 자동으로 입력 파일로 사용합니다.

```text
baekjoon/1026.cpp
baekjoon/1026.in
```
