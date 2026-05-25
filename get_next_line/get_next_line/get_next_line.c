/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:39:39 by marvin            #+#    #+#             */
/*   Updated: 2026/05/25 17:51:04 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_leftover(int fd, char *leftover)
{
	char	*buf;
	ssize_t	bytes_read;

	if (ft_strchr(leftover, '\n'))
		return (leftover);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(leftover), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buf);
		if (!leftover || ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (bytes_read == -1)
		return (free(leftover), NULL);
	return (leftover);
}

static char	*extract_line(char *leftover)
{
	char	*line;
	size_t	i;

	if (!leftover || !leftover[0])
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (leftover[++i] && leftover[i] != '\n')
		line[i] = leftover[i];
	if (leftover[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_leftover(char *leftover)
{
	char	*new_leftover;
	size_t	i;
	size_t	j;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
		return (free(leftover), NULL);
	new_leftover = malloc(ft_strlen(leftover) - i + 1);
	if (!new_leftover)
		return (free(leftover), NULL);
	i++;
	j = 0;
	while (leftover[i])
		new_leftover[j++] = leftover[i++];
	new_leftover[j] = '\0';
	free(leftover);
	if (!new_leftover[0])
		return (free(new_leftover), NULL);
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
	if (!line)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = update_leftover(leftover);
	return (line);
}
