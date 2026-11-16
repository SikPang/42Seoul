# Libft

## 1. 프로젝트 설명

C 표준 라이브러리의 기본 함수를 직접 구현하고, 문자열·메모리·연결 리스트 유틸리티를 정적 라이브러리로 묶은 프로젝트다. 이후 C 프로젝트에서 재사용할 수 있는 기반 코드를 만드는 데 목적이 있다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 메모리 관리와 자료구조 — 포인터·바이트 단위 메모리 접근, 동적 할당과 해제, 연결 리스트와 콜백.

- C, Makefile, `ar`를 이용한 정적 라이브러리 빌드
- 포인터, 바이트 단위 메모리 접근, 동적 할당과 해제
- 문자열 탐색·분할·변환, 파일 디스크립터 출력
- `void *`와 함수 포인터를 활용한 범용 단일 연결 리스트

<br/>

## 3. 핵심 기술 및 설계

- **메모리 조작**: `ft_memcpy`는 순방향으로 바이트를 복사하고, `ft_memmove`는 주소 관계에 따라 복사 방향을 바꿔 겹치는 영역을 처리한다.
- **문자열 생성**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`은 결과 공간을 동적으로 할당한다. 반환받은 공간의 해제 책임은 호출자에게 있다.
- **콜백 기반 처리**: `ft_strmapi`와 `ft_striteri`는 인덱스를 전달하며 문자열을 변환한다. 리스트의 순회·변환·삭제도 콜백으로 동작을 분리한다.
- **기본/보너스 분리**: 기본 함수 34개와 리스트 함수 9개를 별도 소스로 관리하고, `libft.h`에서 인터페이스를 제공한다.

구현 근거: [공개 인터페이스](libft.h), [메모리 이동](ft_memmove.c), [문자열 분할](ft_split.c), [리스트 변환](ft_lstmap_bonus.c), [빌드 설정](Makefile).

<br/>

## 4. 프로그램 실행법

C 컴파일러, `make`, `ar`가 있는 Unix 계열 개발 환경에서 사용한다. 독립 실행 파일 대신 `libft.a`를 생성한다.

```sh
cd 0_Libft
make
# 리스트 함수도 사용할 경우 기본 라이브러리를 먼저 생성한다.
make bonus
```

아래 코드를 `example.c`로 저장한다.

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Hello, Libft!", 1);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror example.c -I. -L. -lft -o libft_example
./libft_example
```

`make clean`은 오브젝트, `make fclean`은 라이브러리까지 정리한다.

<br/>

## 5. 구현 범위

### 기본 함수 34개

- 문자 판별·변환: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
- 메모리: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- 문자열: 길이·복사·결합·비교·탐색, 복제·부분 문자열·양끝 제거·분할
- 변환·순회: `ft_atoi`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
- 출력: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 보너스 및 적용 범위

- `t_list` 노드 생성, 앞·뒤 삽입, 크기·마지막 노드 조회
- 노드 삭제, 전체 해제, 콜백 순회와 새 리스트 생성
- C 표준 라이브러리 전체가 아닌, 헤더에 선언된 함수 집합을 제공한다.
- 별도의 실행 프로그램과 통합 테스트 실행 타깃은 포함하지 않는다.
