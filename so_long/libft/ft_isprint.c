/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:25:08 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:21:53 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

//int main(void)
//{
//    printf("Result for ' ' (32): %d\n", ft_isprint(32));
//    printf("Result for 'A' (65): %d\n", ft_isprint(65));
//    printf("Result for '~' (126): %d\n", ft_isprint(126));
//    printf("Result for '\\n' (10): %d\n", ft_isprint(10));
//    return (0);
//}