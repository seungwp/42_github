/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:00:26 by seukim            #+#    #+#             */
/*   Updated: 2026/02/12 16:58:42 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

//void	my_iter_func(unsigned int i, char *c)
//{
//	if (*c >= 'a' && *c <= 'z')
//		*c -= 32;
//}

//int main(void)
//{
//	char str[] = "hello 42 gs";

//	printf("Before: %s\n", str);

//	ft_striteri(str, my_iter_func);

//	printf("After : %s\n", str);

//	return (0);
//}