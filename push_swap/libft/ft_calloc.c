/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:01:13 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:19:36 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

//int main(void)
//{
//    int     *arr;
//    size_t  i;
//    size_t  count;

//    count = 5;
//    arr = (int *)ft_calloc(count, sizeof(int));
//    if (!arr)
//        return (1);
//    i = 0;
//    while (i < count)
//    {
//        printf("%d ", arr[i]);
//        i++;
//    }
//    free(arr);
//    return (0);
//}