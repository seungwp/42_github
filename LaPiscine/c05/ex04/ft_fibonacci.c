/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:26:13 by seukim            #+#    #+#             */
/*   Updated: 2025/11/06 18:21:35 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

//#include <stdio.h>
//int main(void)
//{	
//	printf("%d\n", ft_fibonacci(-10));
//	printf("%d\n", ft_fibonacci(0));
//	printf("%d\n", ft_fibonacci(1));
//	printf("%d\n", ft_fibonacci(2));
//	printf("%d\n", ft_fibonacci(3));
//	printf("%d\n", ft_fibonacci(4));
//	printf("%d\n", ft_fibonacci(5));
//	printf("%d\n", ft_fibonacci(6));
//	printf("%d\n", ft_fibonacci(7));
//	return (0);
//}