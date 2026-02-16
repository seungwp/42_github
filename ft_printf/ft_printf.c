/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:37:02 by seukim            #+#    #+#             */
/*   Updated: 2026/02/16 15:05:38 by seukim           ###   ########.fr       */
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
//	int	len_ft;
//	int	len_or;

//	printf("--- [1] Char & String ---\n");
//	len_ft = ft_printf("Mine: %c %s\n", 'G', "Gemini");
//	len_or =    printf("Orig: %c %s\n", 'G', "Gemini");
//	printf("Len: %d vs %d\n\n", len_ft, len_or);

//	printf("--- [2] Integer & Unsigned ---\n");
//	len_ft = ft_printf("Mine: %d %i %u\n", INT_MIN, 42, UINT_MAX);
//	len_or =    printf("Orig: %d %i %u\n", INT_MIN, 42, UINT_MAX);
//	printf("Len: %d vs %d\n\n", len_ft, len_or);

//	printf("--- [3] Hex & Pointer ---\n");
//	len_ft = ft_printf("Mine: %x %X %p\n", 255, 255, &len_ft);
//	len_or =    printf("Orig: %x %X %p\n", 255, 255, &len_ft);
//	printf("Len: %d vs %d\n\n", len_ft, len_or);

//	printf("--- [4] Percent & NULL ---\n");
//	len_ft = ft_printf("Mine: %% | %s | %p\n", (char *)NULL, NULL);
//	len_or =    printf("Orig: %% | %s | %p\n", (char *)NULL, NULL);
//	printf("Len: %d vs %d\n", len_ft, len_or);

//	return (0);
//}
// make && cc ft_printf.c libftprintf.a && ./a.out