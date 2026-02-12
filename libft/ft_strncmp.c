/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:36 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:03:53 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//int main(void)
//{
//    printf("Result 1: %d\n", ft_strncmp("1234", "1235", 3));
//    printf("Result 2: %d\n", ft_strncmp("1234", "1235", 4));
//    printf("Result 3: %d\n", ft_strncmp("abcdef", "abcde", 10));
//    printf("Result 4: %d\n", ft_strncmp("test", "test", 10));
//    printf("Result 5: %d\n", ft_strncmp("", "a", 1));

//    return (0);
//}