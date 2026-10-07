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

static int	count_bits(int max_rank)
{
	int	bits;

	bits = 0;
	while ((max_rank >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	size;
	int	bits;
	int	bit;
	int	i;

	assign_rank(a);
	size = stack_size(a);
	bits = count_bits(size - 1);
	bit = 0;
	while (bit < bits)
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
