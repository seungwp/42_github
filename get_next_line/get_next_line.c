/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:39:39 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 14:40:33 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append_chunk(char *res, size_t *len, size_t *cap, char *chunk)
{
	size_t	br;
	size_t	new_cap;
	size_t	i;

	br = ft_strlen(chunk);
	if (*len + br + 1 > *cap)
	{
		new_cap = (*len + br + 1) * 2;
		res = ft_grow(res, *len, new_cap);
		if (!res)
			return (NULL);
		*cap = new_cap;
	}
	i = 0;
	while (i < br)
	{
		res[*len + i] = chunk[i];
		i++;
	}
	*len += br;
	res[*len] = '\0';
	return (res);
}

static char	*fill_res(int fd, char *res, size_t *len, size_t *cap)
{
	char	*buf;
	ssize_t	br;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(res), NULL);
	br = read(fd, buf, BUFFER_SIZE);
	while (br > 0)
	{
		buf[br] = '\0';
		res = append_chunk(res, len, cap, buf);
		if (!res || ft_strchr(buf, '\n'))
			break ;
		br = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (!res || br == -1)
		return (free(res), NULL);
	return (res);
}

static char	*read_to_leftover(int fd, char *leftover)
{
	char	*res;
	size_t	len;
	size_t	cap;

	if (ft_strchr(leftover, '\n'))
		return (leftover);
	len = ft_strlen(leftover);
	cap = (len + BUFFER_SIZE + 1) * 2;
	res = ft_grow(leftover, len, cap);
	if (!res)
		return (NULL);
	return (fill_res(fd, res, &len, &cap));
}

static char	*extract_line(char *leftover)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!leftover || !leftover[0])
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = ft_substr(leftover, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_to_leftover(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line(leftover);
	if (!line)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = update_leftover(leftover);
	return (line);
}
