/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:22:41 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 15:22:41 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

/*
** t_node : 리스트 노드 하나. 기본 필드(value/prev/next)에 더해
**          그리디 정렬용 보조 필드를 함께 둔다. 보조 필드는 sort_big 이
**          매 라운드마다 다시 계산해 채운다(파싱/연산 단계에선 0).
**   index        : 자기 스택에서 top 으로부터의 위치 (0 = top)
**   push_cost    : 이 노드를 정렬 위치로 옮기는 데 드는 총 회전 비용
**   above_median : 1이면 상단 절반(정회전 유리), 0이면 하단 절반(역회전 유리)
**   cheapest     : 1이면 이번 라운드에 가장 싸게 옮길 수 있는 노드
**   target_node  : a 에서 이 노드가 들어갈 목표 노드
**
** t_stack : 스택 손잡이. top/bottom 을 함께 관리해 ra/rra, pa/pb 를 O(1) 에
**           처리한다. 빈 스택은 top/bottom 이 둘 다 NULL.
**  (주의) 노드 타입은 t_node, 스택 전체 타입은 t_stack 이다. libft 가 이미
**         t_list 를 쓰므로 컨테이너 이름을 t_stack 으로 둔다.
*/
typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
}					t_stack;

/* push_swap.c : 진입점 + 정렬 디스패처 */
int			main(int argc, char **argv);

/* parsing.c : argv -> 검증된 정수들을 스택 a 에 채운다 */
int			parse_args(int argc, char **argv, t_stack *a);
void		fill_stack(t_stack *a, char **nums, int n, t_stack *b);

/* parsing_utils.c : 파싱 보조(오버플로 검사 포함) */
long		ft_atol(const char *str);
int			is_valid_number(const char *str);
int			has_duplicate(t_stack *a, long value);

/* error.c : "Error\n" 출력 후 두 스택 해제하고 종료 */
void		error_exit(t_stack *a, t_stack *b);

/* stack_utils.c : 노드/스택 기본 조작 (함수 5개) */
t_node		*stack_new_node(int value);
void		stack_add_top(t_stack *stack, t_node *node);
void		stack_add_bottom(t_stack *stack, t_node *node);
int			stack_size(t_stack *stack);
void		stack_clear(t_stack *stack);

/* sort_utils.c : 정렬 판단/조회 헬퍼 */
int			stack_is_sorted(t_stack *stack);
t_node		*stack_min_node(t_stack *stack);
t_node		*stack_max_node(t_stack *stack);
void		set_index(t_stack *stack);

/* ops_swap.c */
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

/* ops_push.c */
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

/* ops_rotate.c */
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);

/* ops_rrotate.c */
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

/* sort_small.c : n <= 3 특수 케이스 */
void		sort_small(t_stack *a, t_stack *b, int size);
void		sort_two(t_stack *a);
void		sort_three(t_stack *a);

/* sort_big.c : n > 3 그리디 정렬 (오케스트레이션) */
void		sort_big(t_stack *a, t_stack *b);
void		prep_to_b(t_stack *a, t_stack *b);
void		final_rotate(t_stack *a);

/* greedy.c : 비용 계산 + 최저비용 원소 이동 */
void		set_target_a(t_stack *a, t_stack *b);
void		set_cost(t_stack *a, t_stack *b);
t_node		*find_cheapest(t_stack *b);
void		move_cheapest(t_stack *a, t_stack *b);

#endif
