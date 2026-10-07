/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:00:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 16:00:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_node));
	node->value = value;
	return (node);
}

void	stack_add_top(t_stack *stack, t_node *node)
{
	node->prev = NULL;
	node->next = stack->top;
	if (stack->top)
		stack->top->prev = node;
	else
		stack->bottom = node;
	stack->top = node;
}

void	stack_add_bottom(t_stack *stack, t_node *node)
{
	node->next = NULL;
	node->prev = stack->bottom;
	if (stack->bottom)
		stack->bottom->next = node;
	else
		stack->top = node;
	stack->bottom = node;
}

int	stack_size(t_stack *stack)
{
	t_node	*cur;
	int		size;

	size = 0;
	cur = stack->top;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

void	stack_clear(t_stack *stack)
{
	t_node	*next;

	while (stack->top)
	{
		next = stack->top->next;
		free(stack->top);
		stack->top = next;
	}
	stack->bottom = NULL;
}
