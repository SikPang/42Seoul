# C++ Modules

## 1. 프로젝트 설명

C에서 C++로 학습 범위를 넓히기 위해 작성한 단계별 연습 프로젝트 모음이다. CPP00부터 CPP09까지 입출력·객체 수명·상속·다형성·예외·템플릿·STL·정렬을 작은 실행 프로그램으로 구현한다.

각 `CPPxx/exxx` 폴더는 독립적인 Makefile을 가진다. 전체 모듈을 한 번에 실행하는 통합 프로그램은 없다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 프로그래밍 언어와 자료구조·알고리즘 — 객체 수명·메모리 소유권, 캡슐화·상속·다형성, 예외·제네릭 프로그래밍, STL과 정렬.

| 모듈 | 코드에서 다루는 학습 범위 |
| --- | --- |
| CPP00 | 스트림 입출력, 클래스, 연락처 순환 저장 |
| CPP01 | 동적 할당, 포인터·참조, 파일 치환, 멤버 함수 포인터 |
| CPP02 | 정규형 클래스, 고정소수점, 연산자 오버로딩 |
| CPP03 | ClapTrap 계열 상속과 상태 확장 |
| CPP04 | 가상 함수, 추상 클래스, 인터페이스, 객체 복제·소유권 |
| CPP05 | 등급·서명·실행 권한, 예외, 문서 생성 팩터리 |
| CPP06 | 수치 변환, 포인터 직렬화, 런타임 타입 식별 |
| CPP07 | 함수·클래스 템플릿, 범위 검사 배열 |
| CPP08 | STL 탐색, Span, iterator를 제공하는 stack |
| CPP09 | 날짜별 환율 조회, 후위 표기식, 병합·삽입 정렬 |

Makefile은 `-std=c++98 -Wall -Wextra -Werror`를 지정한다. 다만 일부 소스는 `<random>` 등 C++11 이후 기능을 사용해, 모든 과제가 이 설정으로 빌드되는 상태는 아니다.

<br/>

## 3. 핵심 기술 및 설계

- **고정소수점 표현**: `Fixed`는 소수부 8비트를 가진 정수로 값을 저장하고, 정수·실수 변환과 산술·비교·증감 연산자를 제공한다.
- **다형성과 소유권**: Animal 계열에서 가상 함수 호출을 비교하고, Materia 계열에서는 `clone`으로 실제 파생 타입의 복사본을 만든다. 인벤토리는 슬롯에 보관한 객체를 관리한다.
- **권한과 생성 분리**: Bureaucrat·Form 계열은 등급 검사를 통해 서명·실행을 구분한다. `Intern`은 이름과 멤버 함수 포인터를 대응시켜 구체 문서를 생성한다.
- **범용 컨테이너**: `Array<T>`는 동적 배열 복사와 인덱스 예외를 제공하고, `MutantStack<T>`는 기반 컨테이너의 반복자를 노출한다.
- **알고리즘 조합**: RPN은 스택으로 수식을 계산한다. PmergeMe는 쌍 정렬, Jacobsthal 순서의 삽입, 홀수 잔여 원소 처리를 vector·deque에 적용한다.

구현 근거: [Fixed](CPP02/ex02/Fixed.hpp), [Inventory](CPP04/ex03/Inventory.cpp), [Intern](CPP05/ex03/Intern.cpp), [Array](CPP07/ex02/Array.hpp), [PmergeMe](CPP09/ex02/PmergeMe.hpp).

<br/>

## 4. 프로그램 실행법

C++ 컴파일러와 `make`가 있는 Unix 계열 환경에서 각 과제 폴더로 이동해 빌드한다.

```sh
cd "4_CPP Module"

make -C CPP00/ex00
./CPP00/ex00/megaphone "hello, cpp"

make -C CPP07/ex02
./CPP07/ex02/array

make -C CPP09/ex01
./CPP09/ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

make -C CPP09/ex02
./CPP09/ex02/PmergeMe 3 5 9 7 4
```

BitcoinExchange는 현재 디렉터리의 `data.csv`를 사용하므로 해당 폴더에서 실행한다.

```sh
cd CPP09/ex00
make
./btc input.txt
```

실행 파일 이름은 각 Makefile의 `NAME`을 따른다. `make clean`, `make fclean`, `make re`도 과제 폴더 단위로 사용한다.

<br/>

## 5. 구현 범위

### 모듈별 저장된 구현

- CPP00: megaphone, 8개 연락처 PhoneBook. Account는 헤더·테스트만 있고 구현 파일은 비어 있다.
- CPP01: Zombie 생성·군집, 포인터·참조, Weapon 공유, 파일 문자열 치환, Harl·HarlFilter
- CPP02: Fixed의 생성·복사·변환·연산. ex03은 빈 main만 있다.
- CPP03: ClapTrap·ScavTrap·FragTrap. DiamondTrap 과제는 포함하지 않는다.
- CPP04: Animal·WrongAnimal, Brain, 추상 Animal, Materia·Character·Inventory·MateriaSource
- CPP05: Bureaucrat, Form·AForm, 세 종류 실행 문서, Intern
- CPP06: ScalarConverter, Serializer, Base 파생 타입 식별
- CPP07: swap·min·max, iter, Array
- CPP08: easyfind, Span, MutantStack
- CPP09: BitcoinExchange, RPN, PmergeMe


### 실행 전 확인할 현재 제약

- CPP00/ex02: `Account.cpp`가 비어 있어 링크할 구현이 없다.
- CPP02/ex03: Makefile이 존재하지 않는 Zombie 소스를 참조한다.
- CPP01/ex04와 CPP05/ex02·ex03 등은 C++98 설정과 맞지 않는 표준 라이브러리 사용이 있다.
- CPP04/ex01·ex02의 Cat·Dog 복사 생성자는 Brain 포인터를 공유한다. 대입 연산의 값 복사와 달리 복사 생성의 독립적인 소유권은 보장하지 않는다.
- CPP09/ex02는 컨테이너별 처리 시간을 출력하지만, `clock()` 차이를 변환 없이 μs로 표시하므로 플랫폼에 따른 시간 단위 보정이 필요하다.
- 위 예제는 소스와 빌드 설정에 근거한 실행 절차이며, 전체 과제의 빌드·동작 통과를 의미하지 않는다.
