# ft_irc

## 1. 프로젝트 설명

여러 클라이언트가 채널과 개인 메시지로 통신할 수 있는 IRC 서버다. 서버 인증, 사용자·채널 관리, 운영자 권한과 채널 모드, 공지·환영 메시지 봇을 구현한다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 네트워크와 이벤트 기반 I/O — TCP 바이트 스트림과 메시지 경계, 응용 계층 프로토콜, non-blocking I/O·I/O 멀티플렉싱, 상태 머신.

- C++, Makefile, TCP/IPv4 소켓
- BSD `kqueue`·`kevent`, non-blocking I/O
- 수신 버퍼·송신 큐, 메시지 파싱, IRC 숫자 응답
- STL map·set·queue, 싱글턴 관리자, 상태 전이 테이블

Makefile은 C++98을 지정하지만 일부 소스가 `std::string::front/back/pop_back`을 사용해 C++11 이상이 필요하다. 실행 기준 클라이언트는 irssi다.

<br/>

## 3. 핵심 기술 및 설계

- **단일 이벤트 루프**: `SocketHandler`가 listening 소켓을 만들고 `EventHandler`가 `kevent`로 연결·읽기·종료 이벤트를 처리한다. 클라이언트 소켓은 non-blocking으로 설정한다.
- **메시지 경계와 송신**: 불완전하게 수신한 명령은 클라이언트 버퍼에 보관한다. 즉시 다 보내지 못한 출력은 큐에 남겨 재전송하는 함수를 둔다.
- **사용자·채널 분리**: FD와 닉네임으로 사용자를 조회하고, 채널별 멤버·운영자·초대 목록을 별도 관리한다. 인증은 PASS·USER·NICK 상태 비트로 표현한다.
- **MODE 상태 머신**: `+`·`-` 상태와 `i, t, k, o, l` 입력을 함수 포인터 테이블로 대응시켜 모드를 변경한다.
- **봇 기능**: `ebangBot`이 채널 공지와 입장 환영 메시지를 조회·설정한다. 변경에는 채널 운영자 권한을 확인한다.

구현 근거: [이벤트 루프](srcs/Server/EventHandler.cpp), [파싱](srcs/Server/Parser.cpp), [명령 처리](srcs/Command/CommandHandler.cpp), [MODE FSM](srcs/Command/FSM.cpp), [봇](srcs/Bot/Bot.cpp).

<br/>

## 4. 완성 스크린샷 / Gif

![ezgif com-video-to-gif (2)](https://github.com/SikPang/42Seoul/assets/87380790/d6fb46e3-d937-416d-b81a-8e5d68822ace)

![ezgif com-video-to-gif](https://github.com/SikPang/42Seoul/assets/87380790/9513cec1-c6bc-4fb2-89d0-af13ed5b14ac)

![ezgif com-video-to-gif (1)](https://github.com/SikPang/42Seoul/assets/87380790/8b3f7d43-01f9-4f20-aaef-0b1520f7b8ea)

<br/>

## 5. 프로그램 실행법

`sys/event.h`와 `kqueue`를 사용하는 macOS 개발 환경이 기준이다. Linux·Windows에서 그대로 빌드할 수 없다.

현재 소스가 사용하는 문자열 API에 맞춰 C++11 옵션으로 빌드한다.

```sh
cd 5_ft_irc
make CXXFLAGS="-std=c++11 -Wall -Wextra -Werror"
./ircserv 4242 1234
```

서버 인자는 포트와 비밀번호다. 다른 터미널에서 irssi로 연결한다.

```sh
irssi -c 127.0.0.1 -p 4242 -n user1 -w 1234
```

irssi 안에서 다음 명령을 사용할 수 있다.

```text
/join #room
/msg #room hello
/msg user2 hello
/mode #room +i
/msg ebangBot #room GET NOTICE
/msg ebangBot #room SET WELCOME welcome to room
```

직접 프로토콜을 입력할 때는 `nc 127.0.0.1 4242`로 연결한 뒤 아래 순서로 등록한다. 이 구현의 USER 검사는 앞의 두 사용자 이름이 같고 호스트가 연결 주소와 일치해야 한다.

```text
PASS 1234
USER me me 127.0.0.1 :my real name
NICK user1
JOIN #room
PRIVMSG #room :hello
QUIT :bye
```

<br/>

## 6. 구현 범위

### 서버·사용자·채널 명령

- TCP/IPv4 연결과 여러 클라이언트의 이벤트 처리
- PASS·NICK·USER 등록과 인증 상태 관리
- JOIN·PART·QUIT, 채널·개인 PRIVMSG
- PING/PONG, CAP 협상 응답
- KICK·INVITE·TOPIC
- `i`: 초대 전용, `t`: 토픽 변경 권한
- `k`: 채널 키, `o`: 운영자 권한, `l`: 사용자 수 제한
- IRC 숫자 응답과 채널 이벤트 전달


### 봇과 현재 구현의 제한

- ebangBot의 NOTICE·WELCOME 조회·설정
- 채널 입장 시 환영 메시지·공지 전달
- IRC 전체 규격, 서버 간 네트워크, IPv6, TLS는 구현하지 않는다.
- `n` 모드는 외부 발언 제한을 고정하는 방식이며 자유롭게 해제하지 못한다.
- 송신 큐 재전송 함수는 있지만, 현재 이벤트 루프의 쓰기 이벤트 등록·사용자 조회 경로가 완전하게 연결된 상태는 아니다.
