/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:39 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:04:51 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (is_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}

//int main(void)
//{
//    char *res;

//    res = ft_strtrim("   hello 42 gyeongsan   ", " ");
//    printf("Trim space: [%s]\n", res);
//    free(res);

//    res = ft_strtrim("1234hello4321", "1234");
//    printf("Trim numbers: [%s]\n", res);
//    free(res);

//    res = ft_strtrim("aaaaa", "a");
//    printf("Trim all: [%s]\n", res);
//    free(res);

//    res = ft_strtrim("", "abc");
//    printf("Empty string: [%s]\n", res);
//    free(res);

//    return (0);
//}