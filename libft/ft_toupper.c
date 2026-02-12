/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:43 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:05:28 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

//int main(void)
//{
//    printf("a -> %c\n", ft_toupper('a'));
//    printf("z -> %c\n", ft_toupper('z'));
//    printf("A -> %c\n", ft_toupper('A'));
//    printf("4 -> %c\n", ft_toupper('4'));
//    printf("# -> %c\n", ft_toupper('#'));
//    return (0);
//}