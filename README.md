### 알고리즘 공부 후 저장한 소스코드를 저장하기 위한 레포지토리입니다.

## 코딩 테스트 암기 연습

C++ 문법과 알고리즘 패턴을 반복해서 작성하는 자료는
[`coding-test-memory`](./coding-test-memory/)에 정리되어 있습니다.

- `reference/`: 원본 참고 코드
- `practice/`: 직접 작성한 반복 연습 코드
- `progress.md`: 주제별 복습 진도

## 빌드 및 실행

macOS/Linux에서는 `build.sh`에 소스 파일 경로를 넘기면 컴파일 후 바로 실행됩니다.

```bash
./build.sh base/base_code.cpp
./build.sh baekjoon/1026.cpp
```

Windows PowerShell에서는 `build.ps1`을 사용합니다.

```powershell
.\build.ps1 base\base_code.cpp
.\build.ps1 baekjoon\1026.cpp
```

실행 파일은 macOS/Linux에서는 `build/파일명_YYYYMMDD_HHMMSS`, Windows에서는 `build/파일명_YYYYMMDD_HHMMSS.exe` 형식으로 생성됩니다.

소스 파일과 같은 위치에 같은 이름의 `.in` 파일이 있으면 자동으로 입력 파일로 사용합니다.

```text
baekjoon/1026.cpp
baekjoon/1026.in
```

## Windows 준비

Windows에서 `build.ps1`을 사용하려면 PowerShell과 GCC 컴파일러가 필요합니다. PowerShell은 Windows에 기본 포함되어 있고, GCC는 MSYS2로 설치하는 방식을 권장합니다.

1. [MSYS2 공식 사이트](https://www.msys2.org/)에서 설치 파일을 내려받아 설치합니다.
2. 설치 후 `MSYS2 UCRT64` 터미널을 실행합니다.
3. GCC를 설치합니다.

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

4. Windows 환경 변수 `Path`에 아래 경로를 추가합니다.

```text
C:\msys64\ucrt64\bin
```

5. 새 PowerShell 창을 열고 GCC가 인식되는지 확인합니다.

```powershell
g++ --version
gcc --version
```

6. 스크립트 실행이 막히면 현재 사용자 범위에서 로컬 스크립트 실행을 허용합니다.

```powershell
Set-ExecutionPolicy -Scope CurrentUser RemoteSigned
```

설정 변경 없이 한 번만 실행하려면 아래처럼 실행할 수도 있습니다.

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 base\base_code.cpp
```
