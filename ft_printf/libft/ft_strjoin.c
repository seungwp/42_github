/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:59:44 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 17:01:27 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len + 1);
	if (!new_mem)
		return (NULL);
	ft_strlcpy(new_mem, s1, s1_len + 1);
	ft_strlcat(new_mem, s2, s1_len + s2_len + 1);
	return (new_mem);
}

//int main(void)
//{
//    char *s1 = "Hello ";
//    char *s2 = "42 gs!";
//    char *res;

//    res = ft_strjoin(s1, s2);
//    printf("Joined: %s\n", res);
//    free(res);

//    res = ft_strjoin(NULL, "Only s2");
//    printf("Only s2: %s\n", res);
//    free(res);

//    res = ft_strjoin("Only s1", NULL);
//    printf("Only s1: %s\n", res);
//    free(res);

//    return (0);
//}