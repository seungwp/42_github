/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:05:40 by seukim            #+#    #+#             */
/*   Updated: 2025/11/10 19:53:14 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_strlen_total(int size, char **strs)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	return (total);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		total_len;
	int		i;

	if (size == 0)
	{
		join = (char *)malloc(1);
		if (join == NULL)
			return (NULL);
		join[0] = '\0';
		return (join);
	}
	total_len = ft_strlen_total(size, strs) + ft_strlen(sep) * (size - 1);
	join = (char *)malloc(sizeof(char) * (total_len + 1));
	if (join == NULL)
		return (NULL);
	join[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strncat(join, strs[i], ft_strlen(strs[i]));
		if (i != size - 1)
			ft_strncat(join, sep, ft_strlen(sep));
	}
	return (join);
}

#include <stdio.h>
int main(void)
{
    char *arr[] = {"Hello", "42", "strjoin"};
    char *sep = "_";
    char *result;

    result = ft_strjoin(3, arr, sep);
    if (result == NULL)
    {
        printf("Fail!\n");
        return (1);
    }

    printf("Result: %s\n", result);
    free(result);
    return (0);
}
