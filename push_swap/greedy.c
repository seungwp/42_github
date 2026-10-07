/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:00:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 16:00:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack *a, t_stack *b)
{
	t_node	*nb;
	t_node	*na;
	t_node	*best;

	nb = b->top;
	while (nb)
	{
		best = NULL;
		na = a->top;
		while (na)
		{
			if (na->value > nb->value && (!best || na->value < best->value))
				best = na;
			na = na->next;
		}
		if (!best)
			best = stack_min_node(a);
		nb->target_node = best;
		nb = nb->next;
	}
}

static int	rot_cost(t_node *node, int size)
{
	if (node->above_median)
		return (node->index);
	return (size - node->index);
}

void	set_cost(t_stack *a, t_stack *b)
{
	t_node	*n;
	int		size_a;
	int		size_b;
	int		ca;
	int		cb;

	size_a = stack_size(a);
	size_b = stack_size(b);
	n = b->top;
	while (n)
	{
		ca = rot_cost(n->target_node, size_a);
		cb = rot_cost(n, size_b);
		n->push_cost = ca + cb;
		if (n->above_median == n->target_node->above_median)
		{
			n->push_cost = ca;
			if (cb > ca)
				n->push_cost = cb;
		}
		n = n->next;
	}
}

t_node	*find_cheapest(t_stack *b)
{
	t_node	*cur;
	t_node	*best;

	best = b->top;
	cur = b->top;
	while (cur)
	{
		if (cur->push_cost < best->push_cost)
			best = cur;
		cur = cur->next;
	}
	return (best);
}

void	move_cheapest(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = find_cheapest(b);
	if (n->above_median && n->target_node->above_median)
		while (b->top != n && a->top != n->target_node)
			rr(a, b);
	else if (!n->above_median && !n->target_node->above_median)
		while (b->top != n && a->top != n->target_node)
			rrr(a, b);
	while (b->top != n)
	{
		if (n->above_median)
			rb(b);
		else
			rrb(b);
	}
	while (a->top != n->target_node)
	{
		if (n->target_node->above_median)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}
