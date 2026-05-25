/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:39:39 by marvin            #+#    #+#             */
/*   Updated: 2026/05/25 14:17:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_leftover(int fd, char *leftover)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(leftover), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(leftover, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buf);
		if (!leftover)
			break ;
	}
	free(buf);
	if (bytes_read == -1)
	{
		free(leftover);
		return (NULL);
	}
	return (leftover);
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

static char	*update_leftover(char *leftover)
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
	leftover = update_leftover(leftover);
	return (line);
}
