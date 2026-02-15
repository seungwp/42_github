/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:05 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:38:39 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

//int main(void)
//{
//    char src[] = "Hello World!";
//    char dest[20];

//    ft_memcpy(dest, src, 13);
//    printf("dest: %s\n", dest);

//    int n_src[] = {1, 2, 3, 4, 5};
//    int n_dest[5];
//    ft_memcpy(n_dest, n_src, sizeof(int) * 5);

//    int i = 0;
//    while (i < 5)
//    {
//        printf("%d ", n_dest[i]);
//        i++;
//    }
//    printf("\n");

//    return (0);
//}