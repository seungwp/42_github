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

void	sort_small(t_stack *a, t_stack *b, int size)
{
	(void)b;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
}
