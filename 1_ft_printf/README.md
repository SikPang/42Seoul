# ft_printf

## 1. 프로젝트 설명

서식 문자열과 가변 인자를 해석해 표준 출력으로 내보내는 `ft_printf`를 구현한 프로젝트다. 문자·문자열·정수·16진수·포인터 출력을 직접 처리하고, 결과를 `libftprintf.a`로 제공한다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 데이터 표현과 재귀 — 정수의 부호·진법 변환, 재귀 호출, 가변 인자 처리와 시스템 호출 기반 출력.

- C, `stdarg.h`의 `va_list`, `va_start`, `va_arg`, `va_end`
- `write` 기반 출력과 출력 길이 집계
- 재귀를 이용한 10진수·16진수 변환
- 정적 라이브러리와 Makefile 빌드

<br/>

## 3. 핵심 기술 및 설계

- **서식 분기**: `ft_printf.c`가 문자열을 순회하고, `%` 다음 문자를 `convert`에 전달해 출력 함수를 선택한다.
- **출력 책임 분리**: `print_str.c`, `print_decimal.c`, `print_hex.c`가 자료형별 출력을 담당한다. 정수는 상위 자릿수부터 재귀적으로 출력한다.
- **부호·진법 처리**: 부호 있는 정수는 더 넓은 정수형에서 절댓값을 다루고, `%u`는 unsigned로 해석한다. 포인터에는 `0x` 접두사를 붙인다.
- **반환값**: 각 출력 함수가 반환한 문자 수를 합산한다. 문자열의 NULL 포인터는 `(null)`로 출력한다.

구현 근거: [서식 해석](ft_printf.c), [10진수 출력](print_decimal.c), [16진수·주소 출력](print_hex.c), [헤더](ft_printf.h).

<br/>

## 4. 프로그램 실행법

C 컴파일러와 `make`, `ar`가 필요하다.

```sh
cd 1_ft_printf
make
```

아래 코드를 `example.c`로 저장한다.

```c
#include "ft_printf.h"

int main(void)
{
    int value;

    value = 42;
    ft_printf("text=%s decimal=%d hex=%x pointer=%p %%\n",
        "hello", value, value, (void *)&value);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror example.c -I. -L. -lftprintf -o printf_example
./printf_example
```

`test/main.c`는 표준 `printf`와 비교하는 실험 코드다. 의도적으로 잘못된 서식과 타입 조합을 포함하므로, 일반적인 빌드 예제는 위 코드를 사용한다.

<br/>

## 5. 구현 범위

### 지원하는 서식과 출력

| 서식 | 동작 |
| --- | --- |
| `%c` | 문자 |
| `%s` | 문자열 |
| `%p` | 포인터의 16진수 표현 |
| `%d`, `%i` | 부호 있는 10진수 |
| `%u` | 부호 없는 10진수 |
| `%x`, `%X` | 소문자·대문자 16진수 |
| `%%` | 퍼센트 문자 |

- 일반 문자열과 여러 가변 인자의 연속 출력
- 출력 문자 수 반환과 출력 함수의 오류 반환 처리



### 지원 범위의 제한

- 필드 폭, 정밀도, 플래그, 길이 지정자, 부동소수점 서식은 구현하지 않는다.
- 전체 `printf` 호환성을 보장하는 구현은 아니다.
- `print_address`는 내부 재귀 함수의 오류 반환을 확인하지 않아, 모든 출력 실패가 일관되게 전달되는 것은 아니다.
