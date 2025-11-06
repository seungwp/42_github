/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:26:19 by seukim            #+#    #+#             */
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

//#include <stdio.h>
//int main(void)
//{
//	printf("%d\n", ft_is_prime(-1));		// 소수아님 0
//	printf("%d\n", ft_is_prime(0));			// 소수아님 0
//	printf("%d\n", ft_is_prime(1));			// 소수아님 0
//	printf("%d\n", ft_is_prime(2));			// 소수 1
//	printf("%d\n", ft_is_prime(3));			// 소수 1
//	printf("%d\n", ft_is_prime(4));			// 소수 아님 0
//	printf("%d\n", ft_is_prime(5));			// 소수 1
//	printf("%d\n", ft_is_prime(1999));		// 소수 1
//	printf("%d\n", ft_is_prime(199999));	// 소수 1
//	return (0);
//}