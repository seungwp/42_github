/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:09:57 by seukim            #+#    #+#             */
/*   Updated: 2025/11/04 19:10:03 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	
}

#include <stdio.h>
int main(void)
{
	char str1[] = "Hello World!";
	char str2[] = "Hello";
	printf("%s\n", ft_strstr(str1, str2));
	return (0);
}
