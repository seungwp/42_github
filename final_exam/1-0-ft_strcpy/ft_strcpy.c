/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:41:13 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 20:41:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while((s2[i]) != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// #include <stdio.h>

// int main(void)
// {
// 	char str1[] = "Flavio";
// 	char str2[] = "Gaucho";

// 	printf("%s\n", str1);
// 	ft_strcpy(str1, str2);
// 	printf("%s\n", str1);
// 	return (0);
// }