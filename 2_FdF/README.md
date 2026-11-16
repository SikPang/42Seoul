# FdF

## 1. 프로젝트 설명

높이 값이 담긴 지형 파일을 읽어 3차원 와이어프레임으로 시각화하는 프로젝트다. 각 격자점을 화면 좌표로 투영하고 이웃한 점을 선으로 연결해 지형의 형태를 표현한다.

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 컴퓨터 그래픽스와 선형대수 — 좌표 회전·투영, 선분 래스터화(Bresenham), 색상 보간.

- C, MiniLibX, macOS OpenGL·AppKit, 수학 라이브러리
- 3차원 좌표 회전, 등각 투영과 직교 투영
- Bresenham 선분 알고리즘, 색상 보간
- 높이맵 파싱, 연결 리스트, 이미지 버퍼와 키 이벤트

<br/>

## 3. 핵심 기술 및 설계

- **높이맵 구성**: 파일을 줄 단위로 읽고 각 점의 `x, y, z, color`를 저장한다. 행 목록과 각 행의 점 목록을 연결 리스트로 구성하며 행별 너비를 검사한다.
- **좌표 변환**: 원본 점을 복제해 크기를 적용한 뒤 Z축과 X축으로 회전하고 화면 중심 위치를 더한다. 원본 지형과 화면 변환 상태를 분리한다.
- **선분 렌더링**: 가로·세로 이웃 점을 연결한다. 기울기에 따라 Bresenham의 두 경로를 선택하고, 선 위의 위치 비율로 색을 보간한다.
- **색상 입력**: `높이,0x색상` 형식을 읽으며, 색상 정보가 없으면 높이 구간에 따른 기본 색을 사용한다.
- **보너스 상호작용**: 이동·회전·확대·축소·투영 변경 때 이미지 버퍼를 다시 그린다. 현재 위치·회전·확대 상태도 표시한다.

구현 근거: [맵 파싱·초기 배치](Mandatory/main.c), [투영·선 연결](Mandatory/draw/draw.c), [Bresenham](Mandatory/draw/bresenham.c), [보너스 이벤트](Bonus/event_bonus.c).

<br/>

## 4. 완성 스크린샷 / Gif

<img width="800" alt="Screen Shot 2023-11-03 at 3 38 58 PM" src="https://github.com/SikPang/42Seoul/assets/87380790/a1a36451-d11f-4fe0-adf6-069ef48afe90">

<img width="800" alt="Screen Shot 2023-11-03 at 3 37 17 PM" src="https://github.com/SikPang/42Seoul/assets/87380790/193cf547-3d8f-4059-9c94-69398360fbaa">

![1](https://github.com/SikPang/42Seoul/assets/87380790/7c462f8f-58be-4309-8374-541e44934d04)

<img src="https://github.com/SikPang/42Seoul/assets/87380790/ccbb2963-b916-4b3b-b1a0-9cdd64b202f8" width=350/>

![ezgif com-video-to-gif](https://github.com/SikPang/42Seoul/assets/87380790/afadb6b8-26c0-433e-bece-916e83eaa5ca)

![ezgif com-video-to-gif (1)](https://github.com/SikPang/42Seoul/assets/87380790/7d84d72c-860b-46ff-a842-f494befe416b)

![ezgif com-video-to-gif (2)](https://github.com/SikPang/42Seoul/assets/87380790/b9fa7816-6bc5-4b53-83ae-04b73fb77c1c)

<br/>

## 5. 프로그램 실행법

macOS와 Xcode Command Line Tools가 필요하다. 포함된 MiniLibX와 Makefile이 `OpenGL`·`AppKit` 프레임워크를 사용한다.

```sh
cd 2_FdF
make CPPFLAGS="-Imlx_mac"
./fdf test/42.fdf
```

`CPPFLAGS`는 소스의 `<mlx.h>`가 포함된 MiniLibX 헤더를 찾도록 지정한다.

```sh
make bonus CPPFLAGS="-Imlx_mac"
./fdf test/t1.fdf
# 다른 예시
./fdf test/julia.fdf
```

기본과 보너스 모두 실행 파일 이름은 `fdf`다. 맵 파일은 공백으로 구분한 높이 값의 직사각형 격자이며 각 값에 `,0xRRGGBB` 색상을 붙일 수 있다.

| 키 | 동작 |
| --- | --- |
| 방향키 | 지형 이동, 보너스 |
| W / S | X축 회전, 보너스 |
| A / D | Z축 회전, 보너스 |
| + / - | 확대·축소, 보너스 |
| 1 | 기본 등각 투영·배치 복원, 보너스 |
| 2 / 3 | 직교 투영 프리셋, 보너스 |
| Esc / 창 닫기 | 종료 |

<br/>

## 6. 구현 범위

### 기본 구현

- 높이·16진 색상 파싱과 행 너비 검사
- 연결 리스트 기반 격자 저장
- 지형 크기에 따른 초기 배율·위치 계산
- 등각 투영, Bresenham 선 그리기, 선분 색상 보간
- 이미지 버퍼 출력과 종료 이벤트
- 다양한 `.fdf` 샘플 맵

### 보너스 및 적용 범위

- 키보드 이동·회전·확대·축소
- 두 직교 투영 프리셋과 기본 시점 복원
- 위치·회전각·배율 표시
- 높이맵의 격자선 시각화이며 면 채우기나 조명은 구현하지 않는다.
