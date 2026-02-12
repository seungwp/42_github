/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:34 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:05:42 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_mem;
	unsigned int	i;

	i = 0;
	if (!s || !f)
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

//char	my_map_func(unsigned int i, char c)
//{
//	if (c >= 'a' && c <= 'z')
//		return (c - 32);
//	return (c);
//}

//int main(void)
//{
//	char *str = "42 gyeongsan";
//	char *res;

//	res = ft_strmapi(str, my_map_func);
//	if (!res)
//		return (1);
//	printf("Original: %s\n", str);
//	printf("Mapi    : %s\n", res);
//	free(res);
//	return (0);
//}