/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:06:06 by seukim            #+#    #+#             */
/*   Updated: 2026/02/16 14:17:26 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_print_str(str);
	free(str);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*base;
	int		len;

	base = "0123456789";
	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	ft_putchar_fd(base[n % 10], 1);
	return (len + 1);
}
