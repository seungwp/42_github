/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:42:15 by seukim            #+#    #+#             */
/*   Updated: 2025/11/07 13:32:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || !(is_alpha(str[i - 1]) || is_numeric(str[i - 1])))
		{
			if (is_alpha(str[i]))
			{
				str[i] = to_upper(str[i]);
			}
		}
		else if (is_alpha(str[i]))
		{
			str[i] = to_lower(str[i]);
		}
		i++;
	}
	return (str);
}

#include <stdio.h>
int main(void)
{
	char str1[] = "hi, how are you? 42words forty-two; fifty+and+one";
	char str2[] = "hello world";
	char str3[] = "abcABC abc"; 
	printf("%s\n", ft_strcapitalize(str1));
	printf("%s\n", ft_strcapitalize(str2));
	printf("%s\n", ft_strcapitalize(str3));
}