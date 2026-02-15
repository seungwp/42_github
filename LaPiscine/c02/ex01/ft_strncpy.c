/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:04:39 by seukim            #+#    #+#             */
/*   Updated: 2025/11/04 11:22:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char src[] = "abcd";
// 	char dest[20];
// 	int n = 15;
// 	ft_strncpy(dest, src, n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (dest[i] == '\0')
// 			printf("\\0");
// 		else
// 			printf("%c", dest[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }