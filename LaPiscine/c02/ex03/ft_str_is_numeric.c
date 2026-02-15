/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:15:29 by seukim            #+#    #+#             */
/*   Updated: 2025/11/03 20:37:08 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9' )
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
// 	char str1[] = "1234";			// 1
// 	char str2[] = "Hello World";	// 0
// 	char str3[] = "";				// 1
// 	char str4[] = "1234adbc";	    // 0
// 	printf("%d", ft_str_is_numeric(str1));
// 	printf("%d", ft_str_is_numeric(str2));
// 	printf("%d", ft_str_is_numeric(str3));
// 	printf("%d", ft_str_is_numeric(str4));
// 	printf("\n");
// }