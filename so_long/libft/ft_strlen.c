/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:54:02 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:03:21 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}

//int main(void)
//{
//    printf("Len: %zu\n", ft_strlen("42Gyeongsan"));
//    printf("Len: %zu\n", ft_strlen(""));
//    printf("Len: %zu\n", ft_strlen(" "));
//    return (0);
//}