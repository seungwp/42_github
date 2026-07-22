/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:13 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:50:27 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

//int main(void)
//{
//    ft_putnbr_fd(0, 1);
//    write(1, "\n", 1);

//    ft_putnbr_fd(123, 1);
//    write(1, "\n", 1);

//    ft_putnbr_fd(-456, 1);
//    write(1, "\n", 1);

//    ft_putnbr_fd(2147483647, 1);
//    write(1, "\n", 1);

//    ft_putnbr_fd(-2147483648, 1);
//    write(1, "\n", 1);

//    return (0);
//}