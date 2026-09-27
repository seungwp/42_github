/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:24 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:56:01 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

//int main(void)
//{
//    char *str = "Hello World";
//    char *ptr;

//    ptr = ft_strchr(str, 'W');
//    printf("Find 'W': %s\n", ptr);

//    ptr = ft_strchr(str, 'o');
//    printf("Find 'o': %s\n", ptr);

//    ptr = ft_strchr(str, '\0');
//    printf("Find '\\0': %p (is end: %d)\n", ptr, ptr == (str + 11));

//    ptr = ft_strchr(str, 'z');
//    printf("Find 'z': %s\n", ptr);

//    return (0);
//}