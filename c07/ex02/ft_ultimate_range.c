/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:05:38 by seukim            #+#    #+#             */
/*   Updated: 2025/11/09 17:40:40 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
	return (**range);
	return (max - min);
}

#include <stdio.h>
int main(void) 
{
    int min = 1;
	int max = 100;
    int *arr;
	int *range[10][10];
    arr = ft_ultimate_range(*range, min, max);
	int i = 0;
	while (arr[i])
	{
		printf("%d\n", arr[i]);
		i++;
	}
    return 0;
}