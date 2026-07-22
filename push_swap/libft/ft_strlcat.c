/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:29 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:02:41 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dst_len >= size)
		return (size + src_len);
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

//int main(void)
//{
//    char    dst1[20] = "Hello";
//    char    *src = " 42 gs";
//    size_t  res;

//    res = ft_strlcat(dst1, src, 20);
//    printf("Result: %s, Return: %zu\n", dst1, res);

//    char    dst2[10] = "Hello";
//    res = ft_strlcat(dst2, src, 10);
//    printf("Truncated: %s, Return: %zu\n", dst2, res);

//    char    dst3[10] = "Hello";
//    res = ft_strlcat(dst3, src, 3);
//    printf("Small size: %s, Return: %zu\n", dst3, res);

//    return (0);
//}