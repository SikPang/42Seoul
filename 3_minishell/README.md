# minishell

## 1. 프로젝트 설명

프롬프트에서 입력받은 명령을 해석하고 실행하는 소형 Unix 셸이다. 외부 명령 실행뿐 아니라 파이프·리다이렉션·환경변수 확장과 기본 내장 명령을 구현한다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 운영체제와 언어 처리 — 프로세스·파이프·시그널, 어휘·구문 분석, 유한 상태 머신과 이진 탐색 트리.

- C, GNU Readline, 자체 Libft, Makefile
- 토큰화, 재귀 하향 구문 분석, 유한 상태 머신
- `fork`, `execve`, `pipe`, `dup2`, `wait`
- 환경변수 이진 탐색 트리, 연결 리스트
- 시그널, 종료 상태, 파일 디스크립터 복구

<br/>

## 3. 핵심 기술 및 설계

```text
입력 → 토큰화 → here-document 준비 → 환경변수 확장·따옴표 제거
     → 재귀 하향 파싱 → 명령 실행 → 상태·자원 정리
```

- **문법과 실행 분리**: 따옴표 상태를 추적하며 연산자·단어를 나누고, 파서가 파이프·명령·리다이렉션의 배치를 검사해 실행 큐를 만든다.
- **확장 상태 머신**: 일반 문자열·환경변수·작은따옴표·큰따옴표 상태의 전이 테이블로 `$NAME`과 `$?`를 처리한다.
- **환경변수 저장**: 이름 기준 이진 탐색 트리에서 조회·삽입·삭제하고, 중위 순회로 정렬된 `export` 출력과 실행용 환경 배열을 만든다.
- **실행 위치 구분**: 파이프가 없는 내장 명령은 부모 셸에서 실행해 `cd`·`export`의 변경을 유지한다. 외부 명령과 파이프 안의 명령은 자식 프로세스에서 실행한다.
- **FD와 임시 파일**: 표준 입출력을 복제해 명령 실행 뒤 복구한다. here-document는 `/tmp` 파일로 준비하고 사용 후 삭제한다.

구현 근거: [메인 루프](srcs/main.c), [파서](srcs/parsing/recursive_descent_parser1.c), [확장 FSM](srcs/env_var_resolver/env_var_resolver.c), [실행](srcs/process_cmd/execute_cmds2.c), [환경변수 트리](srcs/data_structure/binary_search_tree1.c).

<br/>

## 4. 완성 스크린샷 / Gif

<img width="500" alt="Screen Shot 2023-11-03 at 2 49 51 PM" src="https://github.com/SikPang/42Seoul/assets/87380790/87538ec9-baab-4db3-8419-a0e0d951f3f0">

<img width="500" alt="Screen Shot 2023-11-03 at 2 55 15 PM" src="https://github.com/SikPang/42Seoul/assets/87380790/e9489716-5fb3-4279-9615-f51fd9ffa2a5">

<br/>

## 5. 프로그램 실행법

C 컴파일러, `make`, GNU Readline 헤더·라이브러리가 필요하다. 기존 코드는 macOS 중심으로 작성되었다. 저장소에 Readline 소스가 있지만 기본 Makefile이 이를 자동 빌드하지는 않는다.

시스템에서 Readline을 찾을 수 있으면 다음과 같이 실행한다.

```sh
cd 3_minishell
make
./minishell
```

macOS에서 Homebrew Readline 경로를 명시해야 한다면 프로젝트 폴더에서 다음처럼 빌드한다.

```sh
READLINE_PREFIX="$(brew --prefix readline)"
make IFLAGS="$READLINE_PREFIX/include" \
    CC="cc -L$READLINE_PREFIX/lib"
./minishell
```

셸 안에서 실행할 수 있는 예시다.

```sh
echo hello
export SAMPLE=world
echo "$SAMPLE"
cat < README.md | wc -l
echo "$?"
cat << EOF
hello
EOF
exit
```

Ctrl-C는 입력을 취소하고, Ctrl-D는 EOF로 셸을 종료한다. 시그널 처리는 부모 입력 대기와 자식 실행 상황에 따라 구분한다. 명령 스크립트 파일을 인자로 받는 실행 방식은 제공하지 않는다.

<br/>

## 6. 구현 범위

### 명령 해석과 실행

- 프롬프트·입력 이력
- PATH 검색과 상대·절대 경로의 외부 명령
- 작은따옴표·큰따옴표, 환경변수·마지막 종료 코드 확장
- 파이프 `|`, 리다이렉션 `<`, `>`, `>>`, `<<`
- 문법 오류 감지, 자식 프로세스 회수, 종료 상태 반영
- 임시 파일 정리와 표준 입출력 복구


### 내장 명령 및 제한

- `echo`: `-n` 계열 옵션
- `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- SIGINT·SIGQUIT 및 입력 EOF 처리
- `&&`, `||`, 세미콜론, 백그라운드 작업, 와일드카드 확장은 구현하지 않는다.
- here-document 본문은 읽은 문자열을 그대로 기록하며 환경변수 확장을 적용하지 않는다.
- Bash 전체 호환성이나 모든 오류·시그널 경계 상황의 동등한 동작을 보장하지 않는다.
