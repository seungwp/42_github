/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:09:55 by seukim            #+#    #+#             */
/*   Updated: 2025/11/04 23:53:52 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

//#include <stdio.h>
//int main(void)
//{
//	char dest1[30] = "HELLO";
//	char src1[] = "ab";
//	printf("%s\n", ft_strncat(dest1, src1, 3));
//	char dest2[30] = "monday";
//	char src2[] = "ABCDEFG";
//	printf("%s\n", ft_strncat(dest2, src2, 4));
//}