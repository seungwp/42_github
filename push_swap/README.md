*This project has been created as part of the 42 curriculum by seukim.*

## Description

**push_swap**은 두 개의 스택(`a`, `b`)과 정해진 연산만으로 정수 목록을 오름차순으로 정렬하는 프로젝트입니다.
프로그램은 인자로 받은 정수들을 스택 `a`에 넣고, 정렬에 필요한 연산을 한 줄에 하나씩 표준 출력으로 내보냅니다.

```bash
$ ./push_swap 3 2 1
ra
sa
```

---

## 과제 요구사항 정리

### 규칙
- 스택은 `a`, `b` 두 개. 처음에 `a`에는 중복 없는 정수들, `b`는 비어 있음
- 목표: `a`를 오름차순으로 정렬 (가장 작은 값이 top)
- 첫 번째 인자가 스택의 top

### 사용 가능한 연산

| 연산 | 동작 |
| --- | --- |
| `sa` / `sb` / `ss` | 스택 top 두 원소 교환 (`ss` = 둘 다) |
| `pa` / `pb` | 다른 스택의 top을 가져와 이 스택의 top에 올림 |
| `ra` / `rb` / `rr` | 위로 한 칸 회전 (top → bottom) |
| `rra` / `rrb` / `rrr` | 아래로 한 칸 회전 (bottom → top) |

### 프로그램 동작
| 상황 | 동작 |
| --- | --- |
| 인자 없음 | 아무것도 출력하지 않음 |
| 정수가 아닌 인자 / `int` 범위 초과 / 중복 | 표준 에러에 `Error\n` |
| 정상 입력 | 연산을 `\n`으로 구분해 출력 |

### 공통 규칙
- Norm 준수, 전역 변수 금지
- 메모리 누수 / 비정상 종료(segfault, double free 등) 금지
- `cc -Wall -Wextra -Werror`, Makefile에 `$(NAME) all clean fclean re`, relink 금지
- 허용 함수: `read`, `write`, `malloc`, `free`, `exit`, libft

---

## 구현 방식

### 전체 흐름

```
main
 ├─ parse_args      인자 → 검증 → 스택 a 채우기 (실패 시 error_exit)
 ├─ stack_is_sorted 이미 정렬돼 있으면 아무것도 안 하고 종료
 ├─ n ≤ 40 → sort_small
 │  n ≥ 41 → sort_big (radix)
 └─ stack_clear     두 스택 해제
```

### 자료구조

```c
typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
}					t_stack;
```

- 이중 연결 리스트. `t_stack`이 `top`과 `bottom`을 함께 들고 있어서 `pa`/`pb`/`ra`/`rra`가 모두 **O(1)**
- `rank`: 값의 순위 (가장 작은 값 = 0, 가장 큰 값 = n-1). radix 정렬에서만 사용

### 파싱 (`parsing.c`, `parsing_utils.c`)
1. 인자마다 `ft_split(argv[i], ' ')` → `"3 2 1"`처럼 한 인자에 여러 숫자가 와도 처리
2. 빈 인자(`""`, `" "`)는 에러
3. 숫자마다 검사
   - `is_valid_number`: 부호 하나(선택) + 숫자 하나 이상만 허용 (`"+"`, `"1a"`, `"--1"` 거부)
   - `ft_atol`: long으로 변환. `int` 범위를 넘는 순간 `LONG_MAX`를 돌려서 long 오버플로도 방지
   - 범위 검사 후 `has_duplicate`로 중복 검사
4. 통과하면 `a`의 **bottom**에 추가 → 첫 인자가 top이 됨
5. 하나라도 실패하면 `error_exit`: 두 스택 해제 → `Error\n`(stderr) → `exit(1)`

### 연산 (`ops_*.c`)
과제의 연산 11개 중 알고리즘에 필요한 **5개만** 구현했습니다.

| 파일 | 연산 | 구현 |
| --- | --- | --- |
| `ops_swap.c` | `sa` | top 두 노드의 `value`만 교환 |
| `ops_push.c` | `pa` `pb` | top 노드를 떼어 상대 스택 top에 붙임 (공통 `push` 헬퍼) |
| `ops_rotate.c` | `ra` | top을 떼어 bottom에 붙임 |
| `ops_rrotate.c` | `rra` | bottom을 떼어 top에 붙임 |

연산 함수는 스택을 바꾼 뒤 자기 이름을 출력합니다. 출력은 이 함수들에서만 일어나므로 출력된 연산과 실제 스택 상태가 항상 일치합니다.

### 정렬

**2개** — 뒤집혀 있으면 `sa`

**3개** (`sort_three`, 최대 2연산)
1. 최댓값이 top이면 `ra`, 가운데면 `rra` → 최댓값을 bottom으로
2. 위 두 개가 뒤집혀 있으면 `sa`

**4~40개** (`sort_min_push`, 5개는 최대 10연산)
1. 최솟값을 짧은 쪽 방향(`ra` 또는 `rra`)으로 돌려 top에 올리고 `pb`
2. 3개 남을 때까지 반복 → `sort_three`
3. `pa`로 전부 되돌림 (작은 값부터 다시 위에 쌓임)

**41개 이상** (`sort_big`, 2진수 LSD radix sort)
1. `assign_rank`: 모든 값을 순위(0 ~ n-1)로 바꿈 → 음수·큰 수도 작은 0 이상 정수가 됨
2. 가장 낮은 비트부터 한 비트씩:
   - `a`를 정확히 n번 확인하면서 그 비트가 **0이면 `pb`, 1이면 `ra`**
   - `b`에 간 것을 전부 `pa`로 되돌림
3. 필요한 비트 수(100개 → 7, 500개 → 9)만큼 반복하면 정렬 완료

```
순위: 2(10) 0(00) 3(11) 1(01)
0번 비트로 나눔 → 2 0 | 3 1   (비트 0인 것이 위로)
1번 비트로 나눔 → 0 1 | 2 3   정렬 완료
```

각 단계는 비트가 같은 원소끼리 원래 순서를 유지(안정 분할)하므로, 마지막 비트까지 처리하면 전체가 정렬됩니다.

연산 수 = `n × 비트 수 + (각 비트 단계에서 비트가 0인 원소 수의 합)`.
순위 집합(0 ~ n-1)은 입력 순서와 무관하므로 **연산 수는 항상 같습니다.**

**왜 40개에서 나누나?**
radix는 원소마다 비트 단계마다 무조건 한 번씩 연산하므로 원소가 적으면 손해이고(5개 → 25회), 최솟값 빼기 방식은 연산 수가 n²에 비례해 커집니다.
랜덤 입력으로 비교하면 42개까지는 최솟값 빼기가 radix보다 많았던 적이 없고, 43개부터 역전되는 경우가 생깁니다. 여유를 두고 40을 경계로 잡았습니다.

| n | 최솟값 빼기 (평균 / 최대) | radix |
| --- | --- | --- |
| 5 | ≤ 10 | 25 |
| 20 | 86 / 106 | 160 |
| 40 | 281 / 347 | 380 |
| 50 | 412 / 535 | 467 |

### 파일 구성

| 파일 | 함수 |
| --- | --- |
| `push_swap.h` | 구조체, 함수 선언 |
| `push_swap.c` | `main` |
| `parsing.c` | `parse_args` `fill_stack` `free_split` |
| `parsing_utils.c` | `ft_atol` `is_valid_number` `has_duplicate` |
| `error.c` | `error_exit` |
| `stack_utils.c` | `stack_new_node` `stack_add_top` `stack_add_bottom` `stack_size` `stack_clear` |
| `sort_utils.c` | `stack_is_sorted` `stack_min_node` `stack_max_node` `node_position` `assign_rank` |
| `ops_swap.c` `ops_push.c` `ops_rotate.c` `ops_rrotate.c` | `sa` `pa` `pb` `ra` `rra` |
| `sort_small.c` | `sort_two` `sort_three` `sort_min_push` `sort_small` |
| `sort_big.c` | `sort_big` |

### 결과

| 원소 개수 | 연산 수 | 기준 |
| --- | --- | --- |
| 3 | 6가지 순열 전부 최대 2 | ≤ 3 |
| 5 | 120가지 순열 전부 최대 10 | ≤ 12 |
| 100 | 항상 1084 | < 1100 |
| 500 | 항상 6784 | < 8500 |

norminette 통과, valgrind 누수 없음.

---

## Instructions

```bash
make        # push_swap 빌드 (libft 함께 빌드)
make clean  # 오브젝트 파일 제거
make fclean # 오브젝트 + 실행 파일 제거
make re     # 다시 빌드
```

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"           # 한 인자로 묶어도 됨
./push_swap 4 67 3 87 23 | wc -l     # 연산 횟수

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG   # OK 확인
```

## Resources

- `en.subject.pdf` — 과제 원문
- Radix sort (LSD) — 자릿수(여기서는 비트)마다 안정 분할을 반복하는 비교 없는 정렬
- 42 `checker_linux` — 출력된 연산이 실제로 정렬하는지 확인하는 바이너리
- push_swap visualizer — 연산 과정을 시각적으로 확인

### AI 사용 내역
- 알고리즘 선택 검토 (그리디 방식과 radix 방식 비교)
- 각 `.c` 파일의 구현과 테스트 스크립트(에러 케이스, 순열 전수 검사, 벤치마크) 작성
