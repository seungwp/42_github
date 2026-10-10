/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 16:00:00 by seukim            #+#    #+#             */
/*   Updated: 2026/07/21 16:00:00 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	fill_stack(t_stack *a, char **nums)
{
	t_node	*node;
	long	value;
	int		i;

	i = 0;
	while (nums[i])
	{
		if (!is_valid_number(nums[i]))
			return (0);
		value = ft_atol(nums[i]);
		if (value < INT_MIN || value > INT_MAX || has_duplicate(a, value))
			return (0);
		node = stack_new_node((int)value);
		if (!node)
			return (0);
		stack_add_bottom(a, node);
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	char	**nums;
	int		i;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums)
			return (0);
		if (!nums[0] || !fill_stack(a, nums))
		{
			free_split(nums);
			return (0);
		}
		free_split(nums);
		i++;
	}
	return (1);
}
