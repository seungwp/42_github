/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:00:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 16:00:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_stack *s)
{
	t_node	*node;

	if (!s->top || !s->top->next)
		return ;
	node = s->bottom;
	s->bottom = node->prev;
	s->bottom->next = NULL;
	stack_add_top(s, node);
}

void	rra(t_stack *a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
