# cub3d

## 1. 프로젝트 설명

2차원 맵을 1인칭 3차원 시점으로 렌더링하는 레이캐스팅 프로젝트다. 벽 텍스처, 미니맵, 자동으로 열리고 닫히는 문, 애니메이션 스프라이트를 구현한다.

![3](https://github.com/SikPang/42Seoul/assets/87380790/0dd6ab76-6739-4b85-9e2d-0ffd0b5d6d07)

![4](https://github.com/SikPang/42Seoul/assets/87380790/b9c08862-83b4-4c5b-9531-d7f6e3e5ce2e)

<br/>

## 2. 사용 기술 및 학습 범위

**핵심 CS**: 컴퓨터 그래픽스와 공간 탐색 — DDA 레이캐스팅, 카메라 좌표 변환·원근 투영, 깊이 기반 가림 처리, 충돌 검사와 DFS.

- C, MiniLibX, macOS OpenGL·AppKit
- DDA 레이캐스팅, 카메라 방향·평면 벡터, 회전 행렬
- 원근 투영, 텍스처 샘플링, Z-buffer
- DFS 기반 맵 검증, 연결 리스트·스택
- 키보드·마우스 이벤트와 프레임 갱신

<br/>

## 3. 핵심 기술 및 설계

- **격자 레이 탐색**: 화면의 각 세로 열에 대해 방향 벡터와 카메라 평면으로 광선을 만든다. DDA로 다음 X·Y 격자 경계까지의 거리를 비교하며 벽이나 닫힌 문을 찾는다.
- **원근·텍스처**: 수직 벽 거리로 벽의 화면 높이를 계산하고, 충돌 방향과 위치로 벽 텍스처 및 샘플링 좌표를 선택한다. 천장·바닥은 설정 색으로 채운다.
- **스프라이트 가림**: 스프라이트를 거리순으로 정렬해 카메라 공간으로 변환한다. 각 열의 벽 거리와 Z-buffer를 비교해 가려지는 부분을 처리하며 12장 텍스처를 순환한다.
- **맵 검증**: 4방향 텍스처·RGB·플레이어 시작점을 읽는다. 외곽과 공백 영역을 검사하고, 스택 기반 DFS로 공백이 이동 가능한 공간과 닿는 맵을 거부한다.
- **이동과 문**: 플레이어 양쪽에서 충돌 거리를 확인하고, 문과의 거리에 따라 맵의 열린 문·닫힌 문 상태를 전환한다.

현재 Mandatory와 Bonus 소스는 파일명·헤더명의 보너스 접미사를 제외하면 동일하다. 미니맵·문·스프라이트를 보너스 실행 파일만의 기능으로 구분하지 않는다.

구현 근거: [DDA](Mandatory/srcs/draw/raycasting.c), [벽 렌더링](Mandatory/srcs/draw/draw.c), [스프라이트](Mandatory/srcs/draw/sprite.c), [맵 검증](Mandatory/srcs/parsing/parsing3.c), [이동·문](Mandatory/srcs/move.c).

<br/>

## 4. 완성 스크린샷 / Gif

<img width="800" alt="Screen Shot 2023-11-03 at 3 14 39 PM" src="https://github.com/SikPang/42Seoul/assets/87380790/b95ade83-fec0-47a2-80e9-2ef242b27be3">

<img width="800" alt="Screen Shot 2023-11-03 at 3 14 52 PM" src="https://github.com/SikPang/42Seoul/assets/87380790/fc07531f-f0ee-4b0d-8a83-dcbfc23ff807">

![ezgif com-video-to-gif](https://github.com/SikPang/42Seoul/assets/87380790/d5775952-49e1-4137-9907-259714ca5d8a)

![ezgif com-video-to-gif (1)](https://github.com/SikPang/42Seoul/assets/87380790/3edc3988-bb10-465a-aa2f-94e0505fd449)

![ezgif com-video-to-gif (2)](https://github.com/SikPang/42Seoul/assets/87380790/dd1d2ac7-8beb-49b6-ae7e-45a4c0146b24)

<br/>

## 5. 프로그램 실행법

macOS와 Xcode Command Line Tools가 필요하다. 포함된 MiniLibX와 Makefile은 `OpenGL`·`AppKit`을 사용한다. 텍스처 경로를 찾을 수 있도록 프로젝트 폴더에서 실행한다.

```sh
cd 4_cub3d
make
./cub3D Maps/map.cub

make bonus
./cub3D_bonus Maps/map.cub
```

확장자는 `.cub`여야 한다. 맵 앞부분에는 `NO`, `SO`, `WE`, `EA` 텍스처 경로와 `F`, `C`의 RGB를 지정한다.

| 맵 문자 | 의미 |
| --- | --- |
| 0 / 1 | 빈 공간 / 벽 |
| N / S / E / W | 플레이어 시작 위치와 방향 |
| 3 | 애니메이션 스프라이트 |
| 4 / 5 | 열린 문 / 닫힌 문 |
| 공백 | 맵 외부 영역 |

| 조작 | 동작 |
| --- | --- |
| W / A / S / D | 앞·왼쪽·뒤·오른쪽 이동 |
| 좌·우 방향키 / 마우스 | 시점 회전 |
| 문에 접근·이탈 | 자동 개폐 |
| Esc / 창 닫기 | 종료 |

<br/>

## 6. 구현 범위

### 렌더링과 상호작용

- DDA 레이캐스팅과 방향별 벽 텍스처
- 천장·바닥 색상, 이미지 버퍼 출력
- 벽 충돌 검사와 키보드 이동
- 키보드·마우스 시점 회전
- 플레이어 중심 미니맵
- 거리 기반 문 개폐와 문 테두리 텍스처
- 12프레임 스프라이트 애니메이션과 Z-buffer 가림 처리


### 파싱·빌드 범위와 제한

- 파일 확장자, 설정 중복, RGB 범위 검사
- 플레이어 시작점, 허용 문자, 맵 외곽·공백 연결 검증
- 문 배치 시 맞은편 벽 검사
- `cub3D`, `cub3D_bonus` 별도 빌드 타깃
- 현재 두 타깃의 기능은 동일하다.
- 레이캐스팅 기반 탐색 프로그램이며 전투·적 AI·승리 조건은 구현하지 않는다.
- 애니메이션 주기는 경과 시간 대신 루프 횟수 기준이다.
