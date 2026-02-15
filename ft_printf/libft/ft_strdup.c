/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:37:03 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:57:08 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

//int main(void)
//{
//    char *str = "Hello 42!";
//    char *dup;

//    dup = ft_strdup(str);
//    if (dup == NULL)
//        return (1);
//    printf("Original: %s\n", str);
//    printf("Duplicate: %s\n", dup);
//    printf("Address check: %p vs %p\n", (void *)str, (void *)dup);
//    free(dup);
//    return (0);
//}