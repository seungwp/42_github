/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:00:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 16:00:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	t_node	*max;

	max = stack_max_node(a);
	if (max == a->top)
		ra(a);
	else if (max == a->top->next)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (stack_size(a) > 3)
	{
		min = stack_min_node(a);
		if (node_position(a, min) <= stack_size(a) / 2)
			while (a->top != min)
				ra(a);
		else
			while (a->top != min)
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (b->top)
		pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
		sort_five(a, b);
}
