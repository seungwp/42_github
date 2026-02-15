/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:16:33 by seukim            #+#    #+#             */
/*   Updated: 2025/11/03 20:03:21 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str1[] = "123abcABC";
// 	char str2[] = "Hello World";
// 	char str3[] = "abcABC"; 
// 	char str4[] = "asdf";
// 	char str5[] = "";
// 	printf("%s\n", ft_strupcase(str1));
// 	printf("%s\n", ft_strupcase(str2));
// 	printf("%s\n", ft_strupcase(str3));
// 	printf("%s\n", ft_strupcase(str4));
// 	printf("%s\n", ft_strupcase(str5));
// }