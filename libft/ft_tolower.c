/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:42 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:05:18 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

//int main(void)
//{
//    printf("A -> %c\n", ft_tolower('A'));
//    printf("Z -> %c\n", ft_tolower('Z'));
//    printf("a -> %c\n", ft_tolower('a'));
//    printf("4 -> %c\n", ft_tolower('4'));
//    printf("! -> %c\n", ft_tolower('!'));
//    return (0);
//}