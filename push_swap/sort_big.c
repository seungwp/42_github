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

void	sort_big(t_stack *a, t_stack *b)
{
	int	size;
	int	bit;
	int	i;

	assign_rank(a);
	size = stack_size(a);
	bit = 0;
	while (((size - 1) >> bit) != 0)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->rank >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->top)
			pa(a, b);
		bit++;
	}
}
