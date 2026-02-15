/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:38 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:04:43 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

//int main(void)
//{
//    char *str = "42 Gyeongsan, 42 Seoul";
//    char *ptr;

//    ptr = ft_strrchr(str, '4');
//    printf("Last '4': %s\n", ptr);

//    ptr = ft_strrchr(str, 'G');
//    printf("Last 'G': %s\n", ptr);

//    ptr = ft_strrchr(str, '\0');
//    printf("Last '\\0': %p (is end: %d)\n", ptr, (ptr == str + 22));

//    ptr = ft_strrchr(str, 'z');
//    printf("Last 'z': %s\n", ptr);

//    return (0);
//}