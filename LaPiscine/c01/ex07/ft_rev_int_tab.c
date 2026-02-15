/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:43:42 by marvin            #+#    #+#             */
/*   Updated: 2025/10/31 20:43:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	temp;

	index = 0;
	temp = 0;
	while (index < (size / 2))
	{
		temp = tab[index];
		tab[index] = tab[size -1 - index];
		tab[size - 1 - index] = temp;
		index++;
	}
}

// #include <stdio.h>
// int main(void)
// {	
// 	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
// 	int size = 8;
// 	ft_rev_int_tab(a, size);
// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// 	return (0);
// }