/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 19:32:36 by seukim            #+#    #+#             */
/*   Updated: 2026/10/10 19:38:01 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rect(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		if ((int)ft_strlen(game->map[y]) != game->width)
			error_exit(game, "Map must be rectangular");
		y++;
	}
}

static void	count_tile(t_game *game, int y, int x, int *cnt)
{
	char	c;

	c = game->map[y][x];
	if (c == 'P')
	{
		game->px = x;
		game->py = y;
		cnt[0]++;
	}
	else if (c == 'E')
		cnt[1]++;
	else if (c == 'C')
		game->collect++;
	else if (c != '0' && c != '1')
		error_exit(game, "Map contains an invalid character");
}

static void	check_elements(t_game *game)
{
	int	cnt[2];
	int	x;
	int	y;

	cnt[0] = 0;
	cnt[1] = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			count_tile(game, y, x, cnt);
			x++;
		}
		y++;
	}
	if (cnt[0] != 1)
		error_exit(game, "Map must have exactly one player (P)");
	if (cnt[1] != 1)
		error_exit(game, "Map must have exactly one exit (E)");
	if (game->collect < 1)
		error_exit(game, "Map must have at least one collectible (C)");
}

static void	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1')
			error_exit(game, "Map must be surrounded by walls");
		if (game->map[game->height - 1][x] != '1')
			error_exit(game, "Map must be surrounded by walls");
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			error_exit(game, "Map must be surrounded by walls");
		y++;
	}
}

void	check_map(t_game *game)
{
	check_rect(game);
	check_elements(game);
	check_walls(game);
}
