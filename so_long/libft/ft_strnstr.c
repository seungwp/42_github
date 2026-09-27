/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:37 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:04:11 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j]
			&& (i + j) < len
			&& big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

//int main(void)
//{
//    char *big = "42 Gyeongsan, Hello World!";
//    char *little = "Hello";
//    char *res;

//    res = ft_strnstr(big, little, 30);
//    printf("Test 1: %s\n", res);

//    res = ft_strnstr(big, little, 15);
//    printf("Test 2 (Short len): %s\n", res);

//    res = ft_strnstr(big, "", 10);
//    printf("Test 3 (Empty little): %s\n", res);

//    res = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
//    printf("Test 4: %s\n", res);

//    return (0);
//}