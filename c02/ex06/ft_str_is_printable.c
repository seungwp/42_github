/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:16:30 by seukim            #+#    #+#             */
/*   Updated: 2025/11/03 17:11:07 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
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
// 	char str1[] = "123abcABC";		// 1
// 	char str2[] = "Hello World";	// 1
// 	char str3[] = "";				// 1
// 	char str4[] = "\0";				// 1
// 	char str5[] = "abcABC";	        // 1
// 	char str6[] = "asdg\n";			// 0
// 	char str7[] = {4, '\0'};		// 0
// 	printf("%d", ft_str_is_printable(str1));
// 	printf("%d", ft_str_is_printable(str2));
// 	printf("%d", ft_str_is_printable(str3));
// 	printf("%d", ft_str_is_printable(str4));
// 	printf("%d", ft_str_is_printable(str5));
// 	printf("%d", ft_str_is_printable(str6));
// 	printf("%d", ft_str_is_printable(str7));
// 	printf("\n");
// }