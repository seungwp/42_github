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

int			parse_args(int argc, char **argv, t_stack *a);
int			fill_stack(t_stack *a, char **nums);

long		ft_atol(const char *str);
int			is_valid_number(const char *str);
int			has_duplicate(t_stack *a, long value);

void		error_exit(t_stack *a, t_stack *b);

t_node		*stack_new_node(int value);
void		stack_add_top(t_stack *stack, t_node *node);
void		stack_add_bottom(t_stack *stack, t_node *node);
int			stack_size(t_stack *stack);
void		stack_clear(t_stack *stack);

int			stack_is_sorted(t_stack *stack);
t_node		*stack_min_node(t_stack *stack);
t_node		*stack_max_node(t_stack *stack);
int			node_position(t_stack *stack, t_node *node);
void		assign_rank(t_stack *stack);

void		sa(t_stack *a);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rra(t_stack *a);

void		sort_small(t_stack *a, t_stack *b, int size);
void		sort_two(t_stack *a);
void		sort_three(t_stack *a);
void		sort_five(t_stack *a, t_stack *b);

void		sort_big(t_stack *a, t_stack *b);

#endif
