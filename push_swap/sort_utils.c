/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:00:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 16:00:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

t_node	*stack_min_node(t_stack *stack)
{
	t_node	*cur;
	t_node	*min;

	min = stack->top;
	cur = stack->top;
	while (cur)
	{
		if (cur->value < min->value)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_node	*stack_max_node(t_stack *stack)
{
	t_node	*cur;
	t_node	*max;

	max = stack->top;
	cur = stack->top;
	while (cur)
	{
		if (cur->value > max->value)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

int	node_position(t_stack *stack, t_node *node)
{
	t_node	*cur;
	int		pos;

	pos = 0;
	cur = stack->top;
	while (cur && cur != node)
	{
		pos++;
		cur = cur->next;
	}
	return (pos);
}

void	assign_rank(t_stack *stack)
{
	t_node	*cur;
	t_node	*other;

	cur = stack->top;
	while (cur)
	{
		cur->rank = 0;
		other = stack->top;
		while (other)
		{
			if (other->value < cur->value)
				cur->rank++;
			other = other->next;
		}
		cur = cur->next;
	}
}
