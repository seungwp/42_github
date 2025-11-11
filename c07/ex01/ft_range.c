/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:05:35 by seukim            #+#    #+#             */
/*   Updated: 2025/11/11 19:35:32 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*result;
	int	i;

	if (min >= max)
		return (NULL);
	len = max - min;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = min++;
		i++;
	}
	return (result);
}
