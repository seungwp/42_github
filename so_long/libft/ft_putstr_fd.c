/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:17 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:52:49 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

//int main(void)
//{
//    ft_putstr_fd("Hello, world!", 1);
//    write(1, "\n", 1);
//    ft_putstr_fd("42 gs", 1);
//    write(1, "\n", 1);
//    ft_putstr_fd("", 1);
//    ft_putstr_fd(NULL, 1);
//    return (0);
//}