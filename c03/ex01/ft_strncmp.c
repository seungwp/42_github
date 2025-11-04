/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:09:50 by seukim            #+#    #+#             */
/*   Updated: 2025/11/04 18:04:49 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0') && (s2[i] != '\0'))
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
//	unsigned int n = 4;
//	printf("%d\n", ft_strncmp(str1, str2, n));	// -1
//	printf("%d\n", ft_strncmp(str3, str1, n));	// 25
//	printf("%d\n", ft_strncmp(str3, str4, n));	// 0
//	printf("%d\n", ft_strncmp(str1, str5, n));	// 0
//	return (0);
//}