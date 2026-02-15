/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:09 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:42:34 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
		while (n--)
			ptr_dest[n] = ptr_src[n];
	else
		ft_memcpy(ptr_dest, ptr_src, n);
	return (dest);
}

//int main(void)
//{
//    char str1[] = "123456789";
//    char str2[] = "123456789";

//    ft_memmove(str1 + 5, str1, 4);
//    printf("General: %s\n", str1);

//    ft_memmove(str2 + 2, str2, 5);
//    printf("Overlap: %s\n", str2);

//    return (0);
//}