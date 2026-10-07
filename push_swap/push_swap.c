/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:23:08 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 15:23:08 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		size;

	if (argc < 2)
		return (0);
	a.top = NULL;
	a.bottom = NULL;
	b.top = NULL;
	b.bottom = NULL;
	if (!parse_args(argc, argv, &a))
		error_exit(&a, &b);
	size = stack_size(&a);
	if (!stack_is_sorted(&a))
	{
		if (size <= 5)
			sort_small(&a, &b, size);
		else
			sort_big(&a, &b);
	}
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
