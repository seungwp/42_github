/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 01:38:10 by seukim            #+#    #+#             */
/*   Updated: 2026/10/10 20:51:23 by seukim           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		error_exit(&game, "Usage: ./so_long <map.ber>");
	if (!check_ext(argv[1]))
		error_exit(&game, "Map file must have a .ber extension");
	read_map(&game, argv[1]);
	check_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		error_exit(&game, "Failed to initialize mlx");
	check_screen(&game);
	check_path(&game);
	game.win = mlx_new_window(game.mlx, game.width * TILE,
			game.height * TILE, "so_long");
	if (!game.win)
		error_exit(&game, "Failed to create window");
	load_images(&game);
	render(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 12, 1L << 15, render, &game);
	mlx_loop(game.mlx);
	return (0);
}
