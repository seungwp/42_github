/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:37:36 by marvin            #+#    #+#             */
/*   Updated: 2025/10/31 01:37:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
// int	main(void)
// {
// 	int a = 10;
// 	int b = 3;
// 	int pointed_to_by_div;
// 	int pointed_to_by_mod;

// 	ft_div_mod(a, b, &pointed_to_by_div, &pointed_to_by_mod);

// 	printf("%d, %d\n", pointed_to_by_div, pointed_to_by_mod);
// 	return (0);
// }