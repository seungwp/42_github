/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:37:02 by seukim            #+#    #+#             */
/*   Updated: 2026/03/28 19:56:51 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_formats(ap, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

//#include <stdio.h>
//#include <limits.h>

//int	main(void)
//{
//	printf("--- [1] Char & String ---\n");
//	ft_printf("Mine: %c %s\n", 'G', "Hello World!");
//	printf("Orig: %c %s\n", 'G', "Hello World!");

//	printf("--- [2] Integer & Unsigned ---\n");
//	ft_printf("Mine: %d %i %u\n", INT_MIN, 42, UINT_MAX);
//	printf("Orig: %d %i %u\n", INT_MIN, 42, UINT_MAX);

//	int dummy = 42;

//	printf("--- [3] Hex & Pointer ---\n");
//	ft_printf("Mine: %x %X %p %p\n", 255, 255, &dummy, (void *)0x12345678);
//	printf("Orig: %x %X %p %p\n", 255, 255, &dummy, (void *)0x12345678);

//	printf("--- [4] Percent & NULL ---\n");
//	ft_printf("Mine: %% | %s | %p\n", (char *)NULL, NULL);
//	printf("Orig: %% | %s | %p\n", (char *)NULL, NULL);

//	printf("hello\n");
//	ft_printf("hello\n");

//	return (0);
//}
// make && cc ft_printf.c libftprintf.a && ./a.out