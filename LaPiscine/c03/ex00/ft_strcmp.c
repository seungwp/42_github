/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:09:47 by seukim            #+#    #+#             */
/*   Updated: 2025/11/04 23:53:44 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else
			i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//#include <stdio.h>
//int main(void)
//{
//	char str1[] = "apple";
//	char str2[] = "banana";
//	char str3[] = "zebra";
//	char str4[] = "zebra";
//	char str5[] = "appleZZ";
//	printf("%d\n", ft_strcmp(str1, str2));	// -1 음수
//	printf("%d\n", ft_strcmp(str3, str1));	// 25 양수
//	printf("%d\n", ft_strcmp(str3, str4));	// 0
//	printf("%d\n", ft_strcmp(str1, str5));	// -90 음수
//	return (0);
//}