/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:11:53 by seukim            #+#    #+#             */
/*   Updated: 2026/02/16 14:17:36 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned int n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_put_hex(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
	return (len + 1);
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (format == 'x')
		return (ft_put_hex(n, "0123456789abcdef"));
	else
		return (ft_put_hex(n, "0123456789ABCDEF"));
}
