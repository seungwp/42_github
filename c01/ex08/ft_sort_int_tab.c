/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:13:52 by marvin            #+#    #+#             */
/*   Updated: 2025/10/31 21:13:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>
int main(void)
{
	int a[] = {7, 6, 5, 4, 3, 2, 1};
	int size = 7;

	ft_sort_int_tab(a, size);

	for(int i = 0; i < size; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return (0);
}