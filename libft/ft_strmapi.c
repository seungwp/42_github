/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:34 by seukim            #+#    #+#             */
/*   Updated: 2026/01/27 17:05:31 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_mem;
	unsigned int	i;

	i = 0;
	if (s == 0 || f == 0)
		return (NULL);
	new_mem = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_mem)
		return (NULL);
	while (s[i])
	{
		new_mem[i] = f(i, s[i]);
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}
