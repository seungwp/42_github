/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:04:51 by seukim            #+#    #+#             */
/*   Updated: 2026/10/10 20:04:53 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*join_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static char	*read_file(int fd)
{
	char	buf[BUF_SIZE + 1];
	char	*content;
	int		n;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	n = read(fd, buf, BUF_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		content = join_free(content, buf);
		if (!content)
			return (NULL);
		n = read(fd, buf, BUF_SIZE);
	}
	if (n < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

static int	has_empty_line(char *s)
{
	int	i;

	if (s[0] == '\n')
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	check_content(t_game *game, char *content)
{
	if (content[0] == '\0')
	{
		free(content);
		error_exit(game, "Map file is empty");
	}
	if (has_empty_line(content))
	{
		free(content);
		error_exit(game, "Map contains an empty line");
	}
}

void	read_map(t_game *game, char *path)
{
	int		fd;
	char	*content;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(game, "Cannot open map file");
	content = read_file(fd);
	close(fd);
	if (!content)
		error_exit(game, "Failed to read map file");
	check_content(game, content);
	game->map = ft_split(content, '\n');
	free(content);
	if (!game->map)
		error_exit(game, "Memory allocation failed");
	game->height = 0;
	while (game->map[game->height])
		game->height++;
	game->width = ft_strlen(game->map[0]);
}
