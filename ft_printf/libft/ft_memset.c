/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:57:03 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:43:21 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

//int main(void)
//{
//    char str[10] = "AAAAAAAAA";

//    ft_memset(str, 'B', 5);
//    printf("Result: %s\n", str);

//    int arr[5] = {1, 2, 3, 4, 5};
//    ft_memset(arr, 0, sizeof(int) * 3);
//    printf("Array: %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

//    return (0);
//}