/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:16:28 by seukim            #+#    #+#             */
/*   Updated: 2025/11/03 16:42:50 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z' )
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
// 	char str1[] = "ABCD";			// 1
// 	char str2[] = "Hello World";	// 0
// 	char str3[] = "";				// 1
// 	char str4[] = "abcABC";	        // 0
// 	printf("%d", ft_str_is_uppercase(str1));
// 	printf("%d", ft_str_is_uppercase(str2));
// 	printf("%d", ft_str_is_uppercase(str3));
// 	printf("%d", ft_str_is_uppercase(str4));
// 	printf("\n");
// }