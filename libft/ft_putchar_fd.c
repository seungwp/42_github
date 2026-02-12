/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:12 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:44:17 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

//int main(void)
//{
//    ft_putchar_fd('A', 1);
//    ft_putchar_fd('\n', 1);
//    ft_putchar_fd('H', 1);
//    ft_putchar_fd('i', 1);
//    ft_putchar_fd('\n', 1);
//    return (0);
//}