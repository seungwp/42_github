/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:59:47 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:22:59 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = ft_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (len-- && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

//int main(void)
//{
//    char *s1 = ft_itoa(0);
//    char *s2 = ft_itoa(123);
//    char *s3 = ft_itoa(-456);
//    char *s4 = ft_itoa(2147483647);
//    char *s5 = ft_itoa(-2147483648);

//    printf("%s\n", s1);
//    printf("%s\n", s2);
//    printf("%s\n", s3);
//    printf("%s\n", s4);
//    printf("%s\n", s5);

//    free(s1);
//    free(s2);
//    free(s3);
//    free(s4);
//    free(s5);
//    return (0);
//}