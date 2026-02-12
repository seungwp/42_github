/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:12:59 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:21:34 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

//int main(void)
//{
//    printf("Result for '5': %d\n", ft_isdigit('5'));
//    printf("Result for '0': %d\n", ft_isdigit('0'));
//    printf("Result for 'A': %d\n", ft_isdigit('A'));
//    printf("Result for  48: %d\n", ft_isdigit(48));
//    return (0);
//}