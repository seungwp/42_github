/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:02 by seukim            #+#    #+#             */
/*   Updated: 2026/01/26 11:01:42 by seukim           ###   ########.fr       */
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
