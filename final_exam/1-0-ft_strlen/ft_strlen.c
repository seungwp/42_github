/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:55:16 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 20:55:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

// #include <stdio.h>

// int main(void)
// {
// 	char str[] = "abc";
// 	int len = ft_strlen(str);
// 	printf("%d\n", len);
//  return (0);
// }