/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:31 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:03:01 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

//int main(void)
//{
//    char    dst[20];
//    char    *src = "42 Gyeongsan";
//    size_t  res;

//    res = ft_strlcpy(dst, src, 5);
//    printf("Result: %s, Return: %zu\n", dst, res);

//    res = ft_strlcpy(dst, src, 20);
//    printf("Result: %s, Return: %zu\n", dst, res);

//    res = ft_strlcpy(dst, src, 0);
//    printf("Return (size 0): %zu\n", res);

//    return (0);
//}