*This project has been created as part of the 42 curriculum by seukim.*

## Description

**push_swap** 프로젝트는 두 개의 스택(`a`, `b`)과 제한된 연산 집합만을 사용해 정수 목록을 오름차순으로 정렬하는 프로젝트입니다.

목표는 단순히 정렬을 성공시키는 것이 아니라, **가능한 한 적은 연산 횟수**로 정렬하는 것입니다. 즉 알고리즘의 정확성뿐 아니라 복잡도와 비용에 대한 감각을 기르는 것이 핵심입니다.

프로그램은 인자로 받은 정수들을 스택 `a`에 넣고, 정렬에 필요한 연산들을 한 줄에 하나씩 표준 출력으로 내보냅니다.

```bash
$ ./push_swap 3 2 1
sa
rra
```

## Rules

- 인자는 정수(`int` 범위)여야 하며, 중복이 있어서는 안 됩니다.
- 잘못된 인자가 들어오면 표준 에러로 `Error` 한 줄을 출력하고 종료합니다.
- 인자가 없거나 이미 정렬되어 있으면 아무것도 출력하지 않습니다.

## Operations

| 연산 | 동작 |
| --- | --- |
| `sa` / `sb` / `ss` | 스택 상단 두 원소를 교환 (`ss` = `sa` + `sb`) |
| `pa` / `pb` | 다른 스택의 top 원소를 이 스택의 top으로 push |
| `ra` / `rb` / `rr` | 모든 원소를 위로 한 칸 회전 (top → bottom) |
| `rra` / `rrb` / `rrr` | 모든 원소를 아래로 한 칸 역회전 (bottom → top) |

## Data Structure

```c
typedef struct s_node
{
	int				value;
	int				index;          /* top 으로부터의 위치 (0 = top) */
	int				push_cost;      /* 정렬 위치로 옮기는 데 드는 총 회전 비용 */
	int				above_median;   /* 1이면 상단 절반(정회전 유리) */
	int				cheapest;       /* 1이면 이번 라운드 최저비용 노드 */
	struct s_node	*target_node;   /* a 에서 이 노드가 들어갈 목표 노드 */
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
}					t_stack;
```

이중 연결 리스트로 스택을 구현하고, 컨테이너인 `t_stack`이 `top`과 `bottom`을 함께 들고 있습니다. 덕분에 `ra`/`rra`와 `pa`/`pb`를 모두 **O(1)** 에 처리할 수 있습니다. 빈 스택은 `top`과 `bottom`이 둘 다 `NULL`입니다.

`index`부터 `target_node`까지의 보조 필드는 그리디 정렬 전용이며, `sort_big`이 매 라운드마다 다시 계산해 채웁니다. 파싱·연산 단계에서는 0으로 남습니다.

> 노드 타입은 `t_node`, 스택 전체 타입은 `t_stack`입니다. libft가 이미 `t_list`를 사용하므로 컨테이너 이름을 `t_stack`으로 두었습니다.

## Algorithm

원소 개수에 따라 전략을 나눕니다.

**n ≤ 3 — 하드코딩 (`sort_small.c`)**
2개는 필요하면 `sa` 한 번, 3개는 최대 2연산으로 끝나는 6가지 배열을 직접 처리합니다.

**n > 3 — Turk 방식 그리디 (`sort_big.c`, `greedy.c`)**

1. `prep_to_b` — `a`에 3개만 남기고 나머지를 `b`로 push 합니다. 이때 평균보다 작은 값은 바로 `rb`로 `b` 아래쪽에 보내 `b`를 큰 값/작은 값 두 덩어리로 대충 나눠 둡니다(이후 회전 비용 감소). 남은 3개는 `sort_three`로 정렬합니다.
2. `set_target_a` — `b`의 각 노드에 대해, 그 값보다 크면서 가장 작은 `a`의 노드를 목표(`target_node`)로 지정합니다. 그런 노드가 없으면 `a`의 최솟값이 목표가 됩니다(원형 구조).
3. `set_cost` — 각 노드를 목표 위치까지 옮기는 회전 횟수를 계산합니다. `above_median`으로 정회전/역회전 중 유리한 방향을 고르고, 두 스택을 같은 방향으로 돌릴 수 있으면 `rr`/`rrr`로 묶어 비용을 줄입니다.
4. `find_cheapest` → `move_cheapest` — 비용이 가장 낮은 노드를 골라 실제 회전과 `pa`를 실행합니다. `b`가 빌 때까지 2~4를 반복합니다.
5. `final_rotate` — 마지막으로 최솟값이 top에 오도록 짧은 쪽 방향으로 회전시켜 마무리합니다.

## Files

| 파일 | 역할 |
| --- | --- |
| `push_swap.c` | 진입점, 크기에 따른 정렬 디스패치 |
| `parsing.c` | argv → 검증된 정수들을 스택 `a`에 채움 |
| `parsing_utils.c` | `ft_atol`, 형식 검사, 중복 검사 (오버플로 포함) |
| `error.c` | `Error` 출력 후 두 스택 해제하고 종료 |
| `stack_utils.c` | 노드 생성, top/bottom 삽입, 크기, 해제 |
| `sort_utils.c` | 정렬 여부 판단, 최소/최대 노드, 인덱스 부여 |
| `ops_swap.c` | `sa` `sb` `ss` |
| `ops_push.c` | `pa` `pb` |
| `ops_rotate.c` | `ra` `rb` `rr` |
| `ops_rrotate.c` | `rra` `rrb` `rrr` |
| `sort_small.c` | n ≤ 3 특수 케이스 |
| `sort_big.c` | n > 3 그리디 정렬 오케스트레이션 |
| `greedy.c` | 목표 지정, 비용 계산, 최저비용 원소 이동 |

## Instructions

Makefile을 사용하여 컴파일을 자동화하였습니다. `libft`는 서브 디렉터리에서 자동으로 함께 빌드됩니다.

```bash
make        # push_swap 실행 파일 생성
make clean  # 오브젝트 파일 제거
make fclean # 오브젝트 파일 + 실행 파일 제거
make re     # fclean 후 재빌드
```

컴파일 플래그는 `-Wall -Wextra -Werror`입니다.

## Usage

```bash
$ ./push_swap 4 67 3 87 23
$ ./push_swap "4 67 3 87 23"        # 따옴표로 묶은 한 덩어리도 허용
$ ./push_swap 2 1 3 | wc -l          # 연산 횟수 세기
```

정렬 검증에는 42에서 제공하는 `checker_OS` 바이너리를 사용할 수 있습니다.

```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```

## Performance

| 원소 개수 | 기준 | 측정 결과 (랜덤 입력) |
| --- | --- | --- |
| 3 | ≤ 3 | 6가지 순열 전부 최대 2 |
| 5 | ≤ 12 | 120가지 순열 전부 최대 10 |
| 100 | < 700 | 200회 평균 575, 최대 635 |
| 500 | ≤ 5500 | 1000회 최대 5005, 초과 0회 |

## Status

구현 완료. norminette 통과, valgrind 누수 없음, 위 벤치마크 통과.

## Resources

- `en.subject.pdf` — 프로젝트 원문 과제 명세
- Turk algorithm — push_swap 그리디 접근에 널리 쓰이는 비용 기반 정렬 전략
- 42 checker — 출력된 연산 열의 정합성 검증용 바이너리

## AI Usage Disclosure

본 프로젝트는 다음 작업에 AI를 활용했습니다.

- 자료구조 및 알고리즘 설계 방향 검토
- 각 `.c` 파일의 구현 및 테스트(벤치마크·에러 케이스 검증 스크립트)
- 본 README.md 문서의 작성
