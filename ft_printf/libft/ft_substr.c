/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:41 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:05:04 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_mem;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	new_mem = malloc(sizeof(char) * (len + 1));
	if (!new_mem)
		return (NULL);
	ft_strlcpy(new_mem, s + start, len + 1);
	return (new_mem);
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