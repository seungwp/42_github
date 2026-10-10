/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 01:38:10 by seukim            #+#    #+#             */
/*   Updated: 2026/10/10 18:02:30 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ext(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len <= 4)
		return (0);
	if (ft_strncmp(path + len - 4, ".ber", 4) != 0)
		return (0);
	if (path[len - 5] == '/')
		return (0);
	return (1);
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		error_exit(&game, "Usage: ./so_long <map.ber>");
	if (!check_ext(argv[1]))
		error_exit(&game, "Map file must have a .ber extension");
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit(&game, "Failed to initialize mlx");
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	if (!game.win)
		error_exit(&game, "Failed to create window");
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
