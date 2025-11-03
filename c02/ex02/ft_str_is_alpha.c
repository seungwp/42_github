/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:15:20 by seukim            #+#    #+#             */
/*   Updated: 2025/11/03 20:35:55 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!(is_uppercase(str[i])) && !(is_lowercase(str[i])))
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
// 	char str4[] = "abc],d23";		// 0
// 	printf("%d", ft_str_is_alpha(str1));
// 	printf("%d", ft_str_is_alpha(str2));
// 	printf("%d", ft_str_is_alpha(str3));
// 	printf("%d", ft_str_is_alpha(str4));
// 	printf("\n");
// }