/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:44:57 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:21:09 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

//int main(void)
//{
//    printf("Result for 'A': %d\n", ft_isalpha('A'));
//    printf("Result for 'z': %d\n", ft_isalpha('z'));
//    printf("Result for '1': %d\n", ft_isalpha('1'));
//    printf("Result for '!': %d\n", ft_isalpha('!'));
//    return (0);
//}