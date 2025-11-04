/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:09:57 by seukim            #+#    #+#             */
/*   Updated: 2025/11/04 23:53:53 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			i = 0;
			while (str[i] != '\0' && to_find[i] != '\0' && str[i] == to_find[i])
			{
				i++;
			}
			if (to_find[i] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

//#include <stdio.h>
//int main(void)
//{
//	char str1[] = "Hello World!";
//	char *p;
//	p = ft_strstr(str1, "World");
//	if (p != NULL)
//	{
//		printf("%s\n", p);	// 포인터 시작주소부터 널만날때까지 출력
//		printf("%c\n", *p);	// 포인터 시작주소의 역참조값
//	}
//	else	printf("\n");
//	printf("%s\n", ft_strstr(str1, "o"));
//	return (0);
//}
