/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:26:21 by seukim            #+#    #+#             */
/*   Updated: 2025/11/06 18:21:35 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (nb > i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}

//#include <stdio.h>
//int main(void)
//{
//	printf("%d\n", ft_find_next_prime(-1));		// 2
//	printf("%d\n", ft_find_next_prime(0));		// 2
//	printf("%d\n", ft_find_next_prime(1));		// 2
//	printf("%d\n", ft_find_next_prime(2));		// 2
//	printf("%d\n", ft_find_next_prime(3));		// 3
//	printf("%d\n", ft_find_next_prime(4));		// 5
//	printf("%d\n", ft_find_next_prime(5));		// 5
//	printf("%d\n", ft_find_next_prime(6));		// 7
//	printf("%d\n", ft_find_next_prime(1000));	// 1009
//	return (0);
//}