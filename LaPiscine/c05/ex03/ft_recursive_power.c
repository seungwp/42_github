/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:26:10 by seukim            #+#    #+#             */
/*   Updated: 2025/11/06 18:21:35 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

//#include <stdio.h>
//int main(void)
//{
//	printf("%d\n", ft_recursive_power(2, -1));
//	printf("%d\n", ft_recursive_power(2, 0));
//	printf("%d\n", ft_recursive_power(2, 1));
//	printf("%d\n", ft_recursive_power(2, 2));
//	printf("%d\n", ft_recursive_power(2, 3));
//	printf("%d\n", ft_recursive_power(2, 10));
//	printf("%d\n", ft_recursive_power(5, 2));
//	return (0);
//}