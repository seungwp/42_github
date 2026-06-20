/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:39:39 by marvin            #+#    #+#             */
/*   Updated: 2026/06/19 20:48:20 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

static char	*read_to_storage(int fd, char *storage)
{
	char	*buf;
	ssize_t	read_bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_and_null(storage, NULL));
	read_bytes = 1;
	while (!ft_strchr(storage, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free_and_null(storage, buf));
		buf[read_bytes] = '\0';
		storage = ft_strjoin(storage, buf);
		if (!storage || ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (storage);
}

static char	*split_line(char *storage)
{
	char	*line;
	size_t	i;

	if (!storage || !storage[0])
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

static char	*trim_storage(char *storage)
{
	char	*remains;
	size_t	i;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (free_and_null(storage, NULL));
	remains = ft_substr(storage, i + 1, ft_strlen(storage) - i - 1);
	free(storage);
	if (remains && !remains[0])
		return (free_and_null(remains, NULL));
	return (remains);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_to_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = split_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = trim_storage(storage);
	return (line);
}
