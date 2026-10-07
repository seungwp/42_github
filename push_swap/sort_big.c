/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:00:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 16:00:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_to_b(t_stack *a, t_stack *b)
{
	t_node	*cur;
	long	avg;
	int		size;

	size = stack_size(a);
	avg = 0;
	cur = a->top;
	while (cur)
	{
		avg += cur->value;
		cur = cur->next;
	}
	avg /= size;
	while (size-- > 3)
	{
		pb(a, b);
		if (b->top->next && b->top->value < avg)
			rb(b);
	}
	sort_three(a);
}

void	final_rotate(t_stack *a)
{
	t_node	*min;

	set_index(a);
	min = stack_min_node(a);
	while (a->top != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	prep_to_b(a, b);
	while (b->top)
	{
		set_index(a);
		set_index(b);
		set_target_a(a, b);
		set_cost(a, b);
		move_cheapest(a, b);
	}
	final_rotate(a);
}
