*This project has been created as part of the 42 curriculum by seukim.*

# so_long

## Description

MiniLibX로 만든 2D 게임입니다.
플레이어(`P`)가 맵의 모든 수집품(`C`)을 먹은 뒤 출구(`E`)로 나가면 승리합니다.

- `W` `A` `S` `D`로 상하좌우 이동, 벽(`1`)으로는 이동 불가
- 실제로 이동할 때마다 셸에 `Moves: N` 출력 (벽에 막히면 카운트하지 않음)
- 수집품이 남아 있으면 출구 위에 올라서도 끝나지 않음
- `ESC` 또는 창의 X 버튼으로 종료

맵은 `.ber` 파일이며 아래 5개 문자만 쓸 수 있습니다.

| 문자 | 의미 |
|---|---|
| `0` | 빈 공간 |
| `1` | 벽 |
| `C` | 수집품 |
| `E` | 출구 |
| `P` | 플레이어 시작 위치 |

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Instructions

### 빌드 / 실행

```sh
make                          # libft → minilibx → so_long 순서로 빌드
./so_long maps/valid_mid.ber
```

| 규칙 | 동작 |
|---|---|
| `make` / `make all` | `so_long` 생성 |
| `make clean` | 오브젝트 파일, libft·minilibx 빌드 산출물 삭제 |
| `make fclean` | `clean` + `so_long`, `libft.a` 삭제 |
| `make re` | `fclean` 후 다시 빌드 |

### 테스트 맵

`maps/` 폴더에 정상 맵과 에러 맵이 들어 있습니다.

```sh
./so_long maps/valid_mid.ber      # 가로로 긴 정상 맵
./so_long maps/valid_tall.ber     # 세로로 긴 정상 맵
./so_long maps/err_open_wall.ber  # Error / Map must be surrounded by walls
./so_long maps/ext/map.BER        # Error / Map file must have a .ber extension

valgrind --leak-check=full ./so_long maps/valid_mid.ber   # 누수 확인
```

---

## 전체 흐름

### 한눈에 보기

```
main
 ├─ 1. 인자 검사        argc == 2, 확장자 .ber            (main.c)
 ├─ 2. 맵 읽기          파일 → 문자열 → char **map         (map_read.c)
 ├─ 3. 맵 형식 검사      직사각형 / 문자·개수 / 테두리 벽    (map_check.c)
 ├─ 4. mlx 초기화       mlx_init + 화면 크기 검사           (main.c, render.c)
 ├─ 5. 경로 검사        flood fill로 C, E 도달 가능 확인     (path_check.c)
 ├─ 6. 창·이미지 준비    창 생성 → xpm 5개 로드 → 첫 렌더     (main.c, render.c)
 ├─ 7. 이벤트 등록      키 입력 / X 버튼 / Expose           (main.c)
 └─ 8. mlx_loop        이벤트 대기 → key_press → move_player (move.c)

어느 단계에서든 실패 → error_exit()  : 지금까지 만든 것 모두 해제 → "Error\n메시지" → exit(1)
정상 종료(승리/ESC/X)  → close_game() : 모두 해제 → exit(0)              (exit.c)
```

### 핵심 자료구조 (`includes/so_long.h`)

```c
typedef struct s_game
{
    void    *mlx;      // mlx_init() 결과
    void    *win;      // 창
    char    **map;     // 맵 (NULL로 끝나는 문자열 배열)
    int     width;     // 맵 가로 칸 수
    int     height;    // 맵 세로 칸 수
    int     px, py;    // 플레이어 현재 좌표 (칸 단위)
    int     collect;   // 남은 수집품 수
    int     moves;     // 이동 횟수
    t_img   img;       // 텍스처 5개 (wall, floor, player, collect, exit)
}   t_game;
```

`main`에서 `ft_bzero`로 구조체 전체를 0으로 초기화합니다.
그래서 아직 만들지 않은 포인터는 항상 `NULL`이고, `cleanup()`은 "NULL이 아닌 것만 해제"하면 되므로 **어느 시점에서 실패해도 같은 함수 하나로 정리**할 수 있습니다.

플레이어 위치는 `map`에 `P`로 남겨두지 않고 `px`, `py`로만 관리합니다.
시작 위치의 `P` 칸은 렌더링 시 바닥으로 그려지고, 플레이어 이미지는 항상 `(px, py)` 위에 마지막으로 덧그립니다.

### 1. 인자 검사 — `main.c`

- `argc != 2` → `Usage: ./so_long <map.ber>`
- `check_ext()`: 경로 끝 4글자가 정확히 `.ber`인지 확인
  - 이름 없이 `.ber`만 있는 경우(`.ber`, `maps/.ber`)도 거부
  - `.BER`, `map.ber.txt`는 거부

### 2. 맵 읽기 — `map_read.c`

```
read_map
 ├─ open(path)                       실패 → "Cannot open map file"
 ├─ read_file(fd)                    1024바이트씩 read → 문자열에 이어붙임
 │                                   read 실패(디렉터리 등) → "Failed to read map file"
 ├─ close(fd)
 ├─ check_content(content)
 │   ├─ 빈 파일                       → "Map file is empty"
 │   └─ 빈 줄 (맨 앞 \n, 또는 \n\n)    → "Map contains an empty line"
 ├─ ft_split(content, '\n')          줄 단위 char ** 로 변환
 └─ height = 줄 수, width = 첫 줄 길이
```

빈 줄을 `ft_split` **전에** 검사하는 이유: `ft_split`은 연속된 구분자를 하나로 합쳐버려서, split한 뒤에는 빈 줄이 있었는지 알 수 없기 때문입니다.
파일 마지막 줄 끝의 `\n` 하나는 허용됩니다(`\n\n`만 에러).

### 3. 맵 형식 검사 — `map_check.c`

`check_map`이 아래 순서로 호출합니다.

1. **`check_rect`** — 모든 줄의 길이가 `width`와 같은지 → 아니면 `Map must be rectangular`
2. **`check_elements`** — 모든 칸을 돌며 `count_tile`로 셈
   - `P`: 개수 세고 `px`, `py`에 좌표 저장
   - `E`: 개수 셈
   - `C`: `game->collect` 증가
   - `0`, `1`이 아닌 그 외 문자 → `Map contains an invalid character`
   - 끝난 뒤 `P == 1`, `E == 1`, `C >= 1` 확인
3. **`check_walls`** — 첫 줄·마지막 줄의 모든 칸, 그리고 각 줄의 첫 칸·마지막 칸이 `1`인지

직사각형 검사를 먼저 하는 이유: 이후 검사들이 모든 줄 길이가 `width`라고 가정하고 `map[y][width - 1]` 같은 인덱스에 접근하기 때문입니다.

### 4. mlx 초기화와 화면 크기 검사 — `main.c`, `render.c`

- `mlx_init()` 실패 → `Failed to initialize mlx`
- `check_screen()`: `mlx_get_screen_size`로 모니터 크기를 얻어 `width * 64`, `height * 64`가 넘으면 `Map is too big for the screen`

경로 검사보다 **먼저** 하는 이유는 바로 다음 단계에 있습니다.

### 5. 경로 검사 — `path_check.c`

```
check_path
 ├─ copy_map()       원본 맵을 복사 (원본은 게임에 써야 하므로 건드리지 않음)
 ├─ flood_fill(copy, py, px)
 │     현재 칸이 '1' 또는 이미 칠한 'F'면 멈춤
 │     아니면 'F'로 칠하고 상하좌우 4방향으로 재귀
 ├─ has_unreached()  복사본에 'C'나 'E'가 하나라도 남아 있으면 도달 못 한 것
 │     → "No valid path to all collectibles and the exit"
 └─ free_map(copy)
```

- **범위 검사가 없어도 안전한 이유**: 3단계에서 테두리가 전부 벽임을 확인했으므로, 채우기는 벽에서 반드시 멈추고 맵 밖으로 나갈 수 없습니다.
- **재귀 깊이가 안전한 이유**: 4단계에서 맵을 화면 크기 이하(예: 1920×1080 → 30×16칸)로 제한했으므로 재귀 깊이도 그 칸 수 이하입니다.
- 출구 `E`도 지나갈 수 있는 칸으로 취급합니다. 실제 게임에서도 수집품이 남아 있을 때 출구 위를 지나갈 수 있으므로 같은 규칙입니다.

### 6. 창과 이미지 준비 — `main.c`, `render.c`

1. `mlx_new_window(width * 64, height * 64)` → 실패 시 `Failed to create window`
2. `load_images()` → `load_xpm()`을 5번 호출
   - `mlx_xpm_file_to_image` 실패 → `Failed to load texture`
   - 크기가 64×64가 아니면 → 해당 이미지 해제 후 `Texture size must match TILE`
   - 성공한 이미지는 바로 `game->img`에 저장되므로, 중간에 실패해도 앞서 로드한 이미지는 `cleanup`에서 해제됨
3. `render()`로 첫 화면을 그림

`render()` 동작:

```
모든 칸 (x, y)에 대해:
    '1' → wall, 'C' → collect, 'E' → exit, 그 외('0', 'P') → floor
    를 (x * 64, y * 64) 위치에 그림
마지막으로 player 이미지를 (px * 64, py * 64)에 그림
```

### 7. 이벤트 등록 — `main.c`

| X11 이벤트 | 번호 / 마스크 | 연결 함수 | 용도 |
|---|---|---|---|
| KeyPress | `2`, `1L << 0` | `key_press` | 이동, ESC |
| DestroyNotify | `17`, `0` | `close_game` | 창 X 버튼 |
| Expose | `12`, `1L << 15` | `render` | 창이 가려졌다 다시 보이거나 최소화 후 복원될 때 다시 그림 |

그 다음 `mlx_loop()`가 이벤트를 기다리며 무한 반복합니다.

### 8. 게임 진행 — `move.c`

```
key_press(keycode)
 ├─ ESC → close_game
 ├─ W → move_player( 0, -1)
 ├─ S → move_player( 0, +1)
 ├─ A → move_player(-1,  0)
 └─ D → move_player(+1,  0)

move_player(dx, dy)
 ├─ 다음 칸이 '1'이면 아무것도 안 함 (이동 횟수도 그대로)
 ├─ px, py 갱신, moves++, "Moves: N" 출력
 ├─ 다음 칸이 'C'면 → 맵에서 '0'으로 바꾸고 collect--
 ├─ 다음 칸이 'E'이고 collect == 0이면 → "You win!" 출력 후 close_game
 └─ render()로 다시 그림
```

### 9. 종료와 메모리 정리 — `exit.c`

```
cleanup(game)
 ├─ destroy_images   NULL이 아닌 이미지 5개 mlx_destroy_image
 ├─ mlx_destroy_window
 ├─ mlx_destroy_display + free(mlx)   (Linux MiniLibX는 둘 다 해야 누수 없음)
 └─ free_map(map)

error_exit(game, msg) = cleanup → stderr에 "Error\n" + msg + "\n" → exit(1)
close_game(game)      = cleanup → exit(0)
```

해제 순서는 생성의 역순입니다. 이미지와 창은 `mlx` 포인터가 있어야 해제할 수 있으므로 `mlx`는 마지막에 해제합니다.
`cleanup` 바깥에서 따로 관리하는 메모리는 두 가지뿐이며, 각자 에러를 내기 전에 직접 해제합니다.

- `read_map`의 `content` 문자열 → `check_content`에서 에러 시 `free` 후 `error_exit`
- `check_path`의 맵 복사본 → 에러 시 `free_map(copy)` 후 `error_exit`

### 에러 메시지 전체 목록

모든 에러는 표준 에러로 `Error` 한 줄 + 아래 메시지 한 줄을 출력하고 종료 코드 1로 끝납니다.

| 메시지 | 원인 |
|---|---|
| `Usage: ./so_long <map.ber>` | 인자가 1개가 아님 |
| `Map file must have a .ber extension` | 확장자 오류 |
| `Cannot open map file` | 파일 없음 / 권한 없음 |
| `Failed to read map file` | read 실패 (디렉터리 등) 또는 메모리 부족 |
| `Map file is empty` | 빈 파일 |
| `Map contains an empty line` | 빈 줄 포함 |
| `Map must be rectangular` | 줄 길이가 다름 |
| `Map contains an invalid character` | `0 1 C E P` 외의 문자 |
| `Map must have exactly one player (P)` | P가 0개 또는 2개 이상 |
| `Map must have exactly one exit (E)` | E가 0개 또는 2개 이상 |
| `Map must have at least one collectible (C)` | C가 없음 |
| `Map must be surrounded by walls` | 테두리에 벽이 아닌 칸 |
| `Map is too big for the screen` | 창이 모니터보다 커짐 |
| `No valid path to all collectibles and the exit` | 도달할 수 없는 C 또는 E |
| `Failed to initialize mlx` / `Failed to create window` | MiniLibX 초기화 실패 |
| `Failed to load texture` / `Texture size must match TILE` | xpm 로드 실패 / 64×64 아님 |
| `Memory allocation failed` | malloc 실패 |

## 파일 구조

```
so_long/
├── Makefile
├── includes/so_long.h   구조체, 상수(TILE=64, 키코드), 함수 원형
├── srcs/
│   ├── main.c           인자 검사, 전체 흐름 조립, 이벤트 등록
│   ├── map_read.c       파일 읽기, 빈 줄 검사, split
│   ├── map_check.c      직사각형 / 문자 / 테두리 검사
│   ├── path_check.c     flood fill 경로 검사
│   ├── render.c         텍스처 로드, 화면 크기 검사, 그리기
│   ├── move.c           키 입력, 이동, 승리 판정
│   └── exit.c           메모리 해제, 에러 종료, 정상 종료
├── textures/            64×64 xpm 5개
├── maps/                정상/에러 테스트 맵
├── libft/               직접 만든 libft
└── minilibx-linux/      MiniLibX 소스
```

## Resources

- MiniLibX 매뉴얼: `minilibx-linux/man/` (`man ./minilibx-linux/man/man3/mlx.3`)
- [42 Docs — MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) — 이미지, 이벤트, hook 사용법
- [Xlib Programming Manual — Events](https://tronche.com/gui/x/xlib/events/) — 이벤트 번호(2, 12, 17)와 마스크 의미
- [Flood fill — Wikipedia](https://en.wikipedia.org/wiki/Flood_fill) — 경로 검사 알고리즘
- Valgrind 사용법: `valgrind --leak-check=full --show-leak-kinds=all ./so_long <map>`

### AI 사용

- **코드 리뷰 / 검증**: 완성한 코드가 과제 요구사항을 충족하는지, 오류나 메모리 누수가 없는지 점검하는 데 Claude를 사용했습니다. 에러 맵과 실패 경로(텍스처 로드 실패, mlx 초기화 실패 등)를 valgrind로 확인하는 테스트 시나리오를 함께 만들었습니다.
