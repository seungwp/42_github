/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:16:26 by seukim            #+#    #+#             */
/*   Updated: 2025/11/03 16:38:47 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z' )
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str1[] = "abc";			// 1
// 	char str2[] = "Hello World";	// 0
// 	char str3[] = "";				// 1
// 	char str4[] = "abcABC";	        // 0
// 	printf("%d", ft_str_is_lowercase(str1));
// 	printf("%d", ft_str_is_lowercase(str2));
// 	printf("%d", ft_str_is_lowercase(str3));
// 	printf("%d", ft_str_is_lowercase(str4));
// 	printf("\n");
// }