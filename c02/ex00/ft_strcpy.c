/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:57:41 by seukim            #+#    #+#             */
/*   Updated: 2025/11/02 22:16:40 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

// #include <stdio.h>
// int main(void) 
// {
//     char source[] = "Hello! World!";
//     char destination[20];

//     ft_strcpy(destination, source);
//     printf("복사된 문자열: %s\n", destination);

//     return (0);
// }