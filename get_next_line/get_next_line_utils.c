/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:39:32 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 14:40:32 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= (unsigned int)s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_grow(char *buf, size_t len, size_t new_cap)
{
	char	*new_buf;
	size_t	i;

	new_buf = malloc(new_cap);
	if (!new_buf)
		return (free(buf), NULL);
	i = 0;
	while (i < len)
	{
		new_buf[i] = buf[i];
		i++;
	}
	new_buf[len] = '\0';
	free(buf);
	return (new_buf);
}

char	*update_leftover(char *leftover)
{
	char	*new_leftover;
	size_t	i;

	if (!leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = ft_substr(leftover, i + 1, ft_strlen(leftover) - i - 1);
	free(leftover);
	if (new_leftover && !new_leftover[0])
	{
		free(new_leftover);
		return (NULL);
	}
	return (new_leftover);
}
