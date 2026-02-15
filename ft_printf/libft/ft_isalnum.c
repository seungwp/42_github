/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:15:30 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:20:55 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

//int main(void)
//{
//    printf("Result for 'A': %d\n", ft_isalnum('A'));
//    printf("Result for '1': %d\n", ft_isalnum('1'));
//    printf("Result for '*': %d\n", ft_isalnum('*'));
//    printf("Result for 'z': %d\n", ft_isalnum('z'));
//    return (0);
//}