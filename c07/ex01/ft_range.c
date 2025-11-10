/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:05:35 by seukim            #+#    #+#             */
/*   Updated: 2025/11/10 23:26:53 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*result;
	int		range;
	int		i;

	i = 0;
	range = max - min;
	if (range <= 0)
		return (NULL);
	result = (int *)malloc(sizeof(int) * range);
	if (result == NULL)
		return (NULL);
	while (i < range)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	int min = 1;
// 	int max = 10;
// 	int *arr = ft_range(min, max);

//     if (arr == NULL)
//     {
//         printf("error!\n");
//         return 1;
//     }

//     for (int i = 0; i < max - min; i++)
//         printf("%d ", arr[i]);
//     printf("\n");

//     free(arr);
//     return 0;
// }
