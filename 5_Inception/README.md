# Inception

## 1. 프로젝트 설명

NGINX·WordPress·MariaDB를 각각의 컨테이너로 분리하고 Docker Compose로 연결한 웹 서비스 인프라 프로젝트다. HTTPS 요청부터 PHP 실행, 데이터베이스 저장까지의 흐름을 직접 구성한다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 운영체제·네트워크·데이터 영속성 — 컨테이너의 프로세스 격리와 수명 관리, 가상 네트워크·포트, TLS·FastCGI 통신과 데이터 볼륨.

- Docker, Docker Compose, Debian Bullseye 기반 Dockerfile
- NGINX, OpenSSL, TLS 1.2·1.3
- WordPress, PHP 7.4-FPM, FastCGI, WP-CLI
- MariaDB, SQL 초기화, Bash, 환경변수
- 브리지 네트워크, 바인드 기반 볼륨, `dumb-init`

<br/>

## 3. 핵심 기술 및 설계

```text
브라우저 → NGINX :443 → WordPress/PHP-FPM :9000 → MariaDB :3306
```

- **서비스 분리**: 세 Dockerfile에서 필요한 패키지와 설정을 구성한다. 호스트에는 NGINX의 443 포트만 공개하고, 나머지는 Compose 네트워크 안에서 통신한다.
- **HTTPS 진입점**: NGINX 이미지 빌드 시 자체 서명 인증서를 생성하고, PHP 요청을 `wordpress:9000`으로 전달한다.
- **최초 실행 초기화**: MariaDB는 DB 디렉터리 존재 여부에 따라 데이터베이스·사용자·권한을 생성한다. WordPress는 `index.php`가 없을 때 다운로드·설정 치환·설치를 수행한다.
- **데이터 유지**: WordPress 파일과 DB 파일을 각각 `/home/kwsong/data/wp`, `/home/kwsong/data/db`에 연결한다. NGINX와 PHP-FPM은 WordPress 파일 볼륨을 공유한다.
- **프로세스 운영**: `dumb-init`를 진입점에 두고 서버 프로세스를 포그라운드로 실행한다.

구현 근거: [Compose](srcs/docker-compose.yml), [NGINX 설정](srcs/requirements/nginx/conf/default), [DB 초기화](srcs/requirements/mariadb/tools/settings.sh), [WordPress 초기화](srcs/requirements/wordpress/tools/settings.sh).

<br/>

## 4. 프로그램 실행법

Linux 또는 Linux VM과 Docker 엔진, Compose, `make`가 필요하다. 현재 Makefile은 `docker-compose` 명령과 Linux 경로를 사용한다.

1. `srcs/.env`의 도메인·DB 계정·WordPress 설정을 실행 환경에 맞춘다. 비밀번호와 인증 키는 직접 설정한다.
2. 기본 도메인은 `kwsong.42.fr`이다. 변경한다면 Makefile, NGINX의 `server_name`, `.env`를 함께 맞춘다.
3. 볼륨 경로를 바꾼다면 Makefile과 Compose의 경로도 함께 수정한다.

```sh
cd 5_Inception
make
```

`make`는 hosts 등록에 `sudo`를 사용하고, 데이터 디렉터리를 만든 뒤 컨테이너를 빌드·기동한다. 기본 접속 주소는 [https://kwsong.42.fr](https://kwsong.42.fr)이며, 자체 서명 인증서이므로 브라우저에 인증서 경고가 표시될 수 있다.

Compose V2의 `docker compose`만 설치된 환경에서는 사전 설정 후 다음 명령을 사용할 수 있다.

```sh
sudo mkdir -p /home/kwsong/data/wp /home/kwsong/data/db
# /etc/hosts에 127.0.0.1 kwsong.42.fr 등록
cd srcs
docker compose up --build
# 다른 터미널에서 상태 확인
docker compose ps
```

프로젝트 루트의 `make down`으로 중지한다. `make fclean`과 `make re`는 영속 데이터 삭제를 포함하며, `make clean`은 Docker 전체의 미사용 리소스 정리를 수행한다.

<br/>

## 5. 구현 범위

### 구현된 인프라

- Debian 기반 NGINX·WordPress·MariaDB 이미지
- TLS 1.2·1.3과 443 포트 HTTPS
- FastCGI를 통한 NGINX·PHP-FPM 연동
- DB·사용자·접근 권한 초기화
- WP-CLI 기반 WordPress 설치와 관리자·구독자 생성
- 환경변수로 DB 연결 정보 및 WordPress 인증 키 주입
- 브리지 네트워크, 데이터 볼륨, 재시작 정책


### 현재 구성의 적용 범위

- 추가 캐시·FTP·모니터링 등의 보너스 서비스는 포함하지 않는다.
- 도메인·호스트 데이터 경로가 작성자 환경에 고정되어 있다.
- `depends_on` 외에 DB 준비 완료를 기다리는 healthcheck·재시도 로직은 없다.
- 인증서는 자체 서명 방식이며, 초기화 스크립트에 고정된 구독자 계정 설정이 있다. 외부 공개 전 계정·인증서 설정을 검토해야 한다.
