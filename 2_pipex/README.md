# pipex

## 1. 프로젝트 설명

셸의 파이프와 입출력 리다이렉션을 프로세스 수준에서 재현한 프로젝트다. 입력 파일의 내용을 여러 명령으로 연결해 처리하고 마지막 결과를 출력 파일에 저장한다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 운영체제의 프로세스와 IPC — 프로세스 생성·실행·회수, 파이프 통신, 파일 디스크립터와 입출력 리다이렉션.

- C, POSIX `fork`, `pipe`, `dup2`, `execve`, `wait`
- 파일 디스크립터의 상속·복제·닫기
- 환경변수 `PATH` 탐색과 명령 인자 분리
- here-document, 파일 열기 모드, Makefile

<br/>

## 3. 핵심 기술 및 설계

- **프로세스 연결**: 각 명령에 자식 프로세스를 만들고, `dup2`로 표준 입력·출력을 파일 또는 파이프 끝에 연결한다.
- **단계별 FD 관리**: 이전 파이프와 현재 파이프를 구분해 다음 명령으로 전달하며, 사용이 끝난 FD를 닫고 자식 종료를 기다린다.
- **명령 탐색**: 환경에서 `PATH`를 분리하고 각 디렉터리에 명령 이름을 붙여 `execve`를 시도한다. 따옴표 안의 공백을 고려하는 인자 분리 함수를 사용한다.
- **보너스 확장**: 일반 입력에서는 명령 수를 늘릴 수 있다. `here_doc`는 종료 구분자 전까지 입력을 `.temp`에 저장하고, 출력 파일을 추가 쓰기 모드로 연다.

구현 근거: [기본 파이프 실행](Mandatory/main.c), [FD·PATH 관리](Mandatory/utils.c), [다중 파이프](Bonus/main_bonus.c), [here-document](Bonus/here_doc_bonus.c).

<br/>

## 4. 프로그램 실행법

C 컴파일러와 `make`가 있는 Unix 계열 환경에서 실행한다. 명령은 `PATH`에서 검색하므로 예제처럼 명령 이름을 전달한다.

```sh
cd 2_pipex
make
./pipex input "cat" "wc -l" pipex_result.txt
cat pipex_result.txt
```

이는 셸의 `< input cat | wc -l > pipex_result.txt`에 대응한다.

```sh
make bonus
./pipex input "cat" "sort" "uniq" pipex_result.txt

./pipex here_doc EOF "cat" "wc -l" here_doc_result.txt
# 내용을 입력한 뒤 EOF만 있는 줄을 입력하면 종료된다.
```

`make`와 `make bonus`는 같은 이름의 `pipex`를 생성한다. 일반 모드는 출력 파일을 덮어쓰고, `here_doc` 모드는 결과를 덧붙인다. 여기의 `EOF`는 셸 문법이 아니라 프로그램에 전달하는 인자다.

<br/>

## 5. 구현 범위

### 기본 구현

- `./pipex infile "cmd1" "cmd2" outfile`
- 두 명령의 파이프 연결
- 입력 파일 읽기와 출력 파일 생성·덮어쓰기
- `PATH` 기반 실행 파일 탐색
- 따옴표를 고려한 명령 인자 분리
- 시스템 호출 오류 출력과 자식 프로세스 회수


### 보너스 및 제약

- 일반 입력에서 두 개 이상의 명령을 연결하는 다중 파이프
- `./pipex here_doc LIMITER "cmd1" "cmd2" outfile`
- 현재 `here_doc` 분기는 정확히 두 명령만 받는다.
- 환경변수 확장, 내장 명령 등 완전한 셸 해석은 제공하지 않는다.
- 마지막 명령의 종료 코드를 셸과 동일하게 전파하는 구조는 아니며, 모든 셸 실행 경로와 동등한 호환성을 보장하지 않는다.
