/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:35:33 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 22:35:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char *str)
{
	int i = 0;
	while(str[i])
	{

	if((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
	{
		char a;
		a = str[i] + 1;
		write(1, &a, 1);
	}
	else if(str[i] == 'z' || str[i] == 'Z')
	{
		char b;
		b = str[i] - 25;
		write(1, &b, 1);
	}
	else
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if(ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return(0);
}