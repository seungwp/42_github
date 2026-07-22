/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:01:12 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:15:49 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}

//int main(void)
//{
//    char str[10] = "abcdefghi";
//    size_t i;
//    ft_bzero(str, 5);
//    i = 0;
//    while (i < 10)
//    {
//        printf("%d ", str[i]);
//        i++;
//    }
//    return (0);
//}