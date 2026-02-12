/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:02 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:35:46 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	find_c;
	size_t			i;

	ptr = (unsigned char *)s;
	find_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == find_c)
			return (ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

//int main(void)
//{
//    char    str[] = "Hello World";
//    char    *ptr;

//    ptr = ft_memchr(str, 'W', 11);
//    printf("Find 'W': %s\n", ptr);

//    ptr = ft_memchr(str, 'o', 5);
//    printf("Find 'o' in 5 bytes: %s\n", ptr);

//    ptr = ft_memchr(str, 'z', 11);
//    printf("Find 'z': %p\n", ptr);

//    return (0);
//}