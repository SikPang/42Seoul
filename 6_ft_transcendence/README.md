# ft_transcendence

## 1. 프로젝트 설명

실시간 1:1 Pong 게임에 채팅·친구·프로필·42 OAuth 로그인을 결합한 팀 웹 프로젝트다. 브라우저에서 Unity WebGL 게임을 실행하고, 웹 서버와 소켓 서버가 인증·매칭·메시지·경기 결과를 처리한다.

이 폴더에는 원래 팀 저장소 링크만 있으며 실행 소스는 포함하지 않는다. 아래 설명은 [팀 저장소](https://github.com/42Seoul-LastDance/ft_transcendence)의 `main`에서 확인한 커밋 [`6e7c616`](https://github.com/42Seoul-LastDance/ft_transcendence/tree/6e7c616ebb082805cc0e0ef88b102b198559d2f7)의 웹 소스와 배포 설정을 기준으로 한다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 네트워크·데이터베이스·인증 — 클라이언트·서버의 실시간 이벤트 통신과 상태 동기화, 관계형 데이터 모델링·영속성, OAuth2·JWT와 해시 기반 인증 코드 검증.

| 영역 | 사용 기술 및 학습 내용 |
| --- | --- |
| 프런트엔드 | TypeScript, Next.js 13, React 18, Redux Toolkit, MUI, Tailwind CSS |
| 백엔드 | NestJS 10, TypeORM, PostgreSQL, REST API |
| 실시간 통신 | Socket.IO, namespace·room, 연결·접속 상태 관리 |
| 인증 | 42 OAuth2, Passport, JWT·refresh token, 이메일 2차 인증 |
| 게임 연동 | Unity WebGL 빌드, react-unity-webgl, JavaScript 이벤트 교환 |
| 배포 | Docker, Compose, Bash, 서비스별 볼륨·환경변수 |

<br/>

## 3. 핵심 기술 및 설계

- **웹·게임 연결**: React가 Unity WebGL을 로드한다. Unity에서 발생한 이동·충돌·검증 이벤트를 Socket.IO로 전송하고, 수신한 시작·이동·공 동기화·종료 이벤트를 Unity 객체의 메서드에 전달한다.
- **매칭과 경기 상태**: 서버가 모드별 매칭 대기열·초대·준비 상태·게임 방을 관리한다. 기본·어려움 모드, 득점과 5점 종료, 이탈·연결 해제·비정상 상태에 따른 종료 분기가 있다.
- **게임 검증**: 공·패들의 위치·크기 등을 서버의 기준값과 대조한다. 클라이언트 이벤트를 검증·중계하는 구조이므로 모든 물리를 서버에서 계산하는 모델로 설명하지 않는다.
- **실시간 대화**: 채팅 방의 소유자·운영자·멤버·초대·추방·차단·음소거 상태를 관리한다. 채팅 방 정보는 메모리에 보관하고, DM은 엔티티를 통해 저장·최근 내역을 조회한다.
- **인증과 기록**: OAuth 사용자 정보로 계정을 연결하고 JWT를 발급·갱신한다. 선택한 이메일 2차 인증의 코드를 해시로 저장·검증하며, 경기 결과·경험치·레벨·친구·차단 정보를 DB에서 관리한다.
- **서비스 분리**: Next.js·NestJS·PostgreSQL을 Compose의 별도 서비스로 구성하고, 프런트엔드는 4242·백엔드는 3000 포트를 사용한다.

코드 근거: [Unity 연결](https://github.com/42Seoul-LastDance/ft_transcendence/blob/6e7c616ebb082805cc0e0ef88b102b198559d2f7/srcs/next/src/app/game/game.tsx), [게임 서비스](https://github.com/42Seoul-LastDance/ft_transcendence/blob/6e7c616ebb082805cc0e0ef88b102b198559d2f7/srcs/nest/src/game/game.service.ts), [채팅 서비스](https://github.com/42Seoul-LastDance/ft_transcendence/blob/6e7c616ebb082805cc0e0ef88b102b198559d2f7/srcs/nest/src/socket/chatRoom/chatRoom.service.ts), [인증](https://github.com/42Seoul-LastDance/ft_transcendence/blob/6e7c616ebb082805cc0e0ef88b102b198559d2f7/srcs/nest/src/auth/auth.service.ts), [Compose](https://github.com/42Seoul-LastDance/ft_transcendence/blob/6e7c616ebb082805cc0e0ef88b102b198559d2f7/docker-compose.yml).

<br/>

## 4. 프로그램 실행법

현재 폴더에서는 실행할 수 없다. 별도 작업 위치에 팀 저장소를 내려받고 Docker·Compose가 동작하는 Unix 계열 환경을 준비한다. 이미지가 의존성을 설치하므로 빌드 중 네트워크 연결도 필요하다.

```sh
git clone --recurse-submodules https://github.com/42Seoul-LastDance/ft_transcendence.git
cd ft_transcendence
```

`env` 서브모듈은 별도 저장소다. 해당 저장소에 접근할 수 있어야 하며, 제공된 환경 파일을 사용하거나 동일한 변수 구성을 직접 준비해야 한다.

주요 설정은 다음과 같다.

- DB: `DB_HOST`, `DB_PORT`, `DB_NAME`, `POSTGRES_USER_ID`, `POSTGRES_USER_PASSWORD`, `POSTGRES_PASSWORD`
- OAuth: `FT_CLIENT_ID`, `FT_CLIENT_SECRET`, `FT_CALLBACK`
- JWT: `JWT_SECRET_KEY`, `JWT_2FA_SECRET_KEY`, `JWT_ACCESS_EXPIRATION_TIME`, `JWT_REFRESH_EXPIRATION_TIME`
- 메일: `GMAIL_USER_ID`, `GMAIL_USER_PASSWORD`
- 주소: `NEXT_PUBLIC_BACK_URL`, `FRONT_URL`

```sh
cp env/.env .env
mkdir -p srcs/postgresql
# .env의 계정·키·주소를 실제 환경에 맞게 설정한다.
docker compose up --build
```

프런트엔드는 `http://<호스트 IP>:4242`, API는 `http://<호스트 IP>:3000`이다. 로컬 실행이면 호스트 IP 대신 `localhost`를 사용할 수 있지만, 환경변수와 OAuth에 등록한 콜백 주소도 일치해야 한다.

원본 Makefile의 `make`는 환경 파일 복사, IP 설정 스크립트, `docker-compose`를 사용한다. 위 명령은 설정을 직접 준비하는 실행 경로다. 종료할 때는 `docker compose down`을 사용한다.

<br/>

## 5. 구현 범위

### 웹 서비스와 게임 기능

- 42 OAuth 로그인, 토큰 발급·갱신·로그아웃
- 이메일 코드 기반 2차 인증
- 사용자 프로필·이미지·이름 설정
- 친구 요청·수락·삭제, 차단 목록, 접속 상태
- 공개·비공개·비밀번호 채팅 방과 DM
- 운영 권한 부여, 초대, kick·ban·mute
- 모드별 게임 매칭과 친구 초대 경기
- 준비·시작·득점·종료·이탈 처리, 이모지
- 경기 기록과 경험치·레벨·전적 조회


### 저장소 구성과 확인 범위

- 이 폴더에는 팀 저장소 안내 문서만 저장한다.
- 연결된 팀 저장소에는 웹 프런트엔드·백엔드·배포 설정과 Unity WebGL 빌드가 있다.
- 해당 커밋의 트리에는 Unity Editor 원본 C# 프로젝트가 없어 내부 게임 로직까지 분석한 것으로 간주하지 않는다.
- 실행에는 별도 환경 설정·OAuth 앱·메일 인증 정보가 필요하다.
- Dockerfile의 `node:latest`·`postgres:latest`는 버전이 고정되어 있지 않다. 기존 의존성과의 호환성 및 실제 기동은 별도 검증이 필요하다.
- 채팅 방 상태의 재시작 후 복원과 완전한 서버 권한형 게임 물리는 이 구현 범위에 포함하지 않는다.
