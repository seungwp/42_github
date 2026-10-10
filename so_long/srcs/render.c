/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:44:20 by seukim            #+#    #+#             */
/*   Updated: 2026/10/10 21:14:21 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_xpm(t_game *game, char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
		error_exit(game, "Failed to load texture");
	if (w != TILE || h != TILE)
	{
		mlx_destroy_image(game->mlx, img);
		error_exit(game, "Texture size must match TILE");
	}
	return (img);
}

void	load_images(t_game *game)
{
	game->img.wall = load_xpm(game, "textures/wall.xpm");
	game->img.floor = load_xpm(game, "textures/floor.xpm");
	game->img.player = load_xpm(game, "textures/player.xpm");
	game->img.collect = load_xpm(game, "textures/collect.xpm");
	game->img.exit = load_xpm(game, "textures/exit.xpm");
}

void	check_screen(t_game *game)
{
	int	sw;
	int	sh;

	mlx_get_screen_size(game->mlx, &sw, &sh);
	if (game->width * TILE > sw || game->height * TILE > sh)
		error_exit(game, "Map is too big for the screen");
}

static void	*tile_image(t_game *game, char c)
{
	if (c == '1')
		return (game->img.wall);
	if (c == 'C')
		return (game->img.collect);
	if (c == 'E')
		return (game->img.exit);
	return (game->img.floor);
}

int	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				tile_image(game, game->map[y][x]), x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		game->px * TILE, game->py * TILE);
	return (0);
}
