/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:26:17 by seukim            #+#    #+#             */
/*   Updated: 2025/11/06 18:21:35 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{	
	int	i;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	i = 2;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

//#include <stdio.h>
//int main(void)
//{
//	printf("%d\n", ft_sqrt(-1));	// 0
//	printf("%d\n", ft_sqrt(0));		// 0
//	printf("%d\n", ft_sqrt(1));		// 1
//	printf("%d\n", ft_sqrt(2));		// 0
//	printf("%d\n", ft_sqrt(3));		// 0
//	printf("%d\n", ft_sqrt(4));		// 2
//	printf("%d\n", ft_sqrt(5));		// 0
//	printf("%d\n", ft_sqrt(9));		// 3
//	printf("%d\n", ft_sqrt(25));	// 5
//	return (0);
//}