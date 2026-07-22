/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:03 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:36:43 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

//int main(void)
//{
//    char s1[] = "abcde";
//    char s2[] = "abcef";
//    char s3[] = "abcde";

//    printf("Same: %d\n", ft_memcmp(s1, s3, 5));
//    printf("Diff (s1 < s2): %d\n", ft_memcmp(s1, s2, 5));
//    printf("Diff (s2 > s1): %d\n", ft_memcmp(s2, s1, 5));
//    printf("Compare only 3 bytes: %d\n", ft_memcmp(s1, s2, 3));

//    return (0);
//}