/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:19:31 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 20:19:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int len(char c)
{
	int index = 0;

	if (c >= 'a' && c <= 'z')
	{
		index = c - 'a' + 1;
		return (index);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		index = c - 'A' + 1;
		return (index);
	}
	else
		return (1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int index;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		index = len(argv[1][i]);
		while(index)
		{
			write(1, &argv[1][i], 1);
			index--;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}