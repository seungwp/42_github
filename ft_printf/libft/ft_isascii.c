/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:19:53 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:21:21 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

//int main(void)
//{
//    printf("Result for 0: %d\n", ft_isascii(0));
//    printf("Result for 127: %d\n", ft_isascii(127));
//    printf("Result for 128: %d\n", ft_isascii(128));
//    printf("Result for 'A': %d\n", ft_isascii('A'));
//    return (0);
//}