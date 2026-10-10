/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 01:37:02 by seukim            #+#    #+#             */
/*   Updated: 2026/10/10 20:50:30 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE 64
# define BUF_SIZE 1024
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		px;
	int		py;
	int		collect;
	int		moves;
	t_img	img;
}	t_game;

/* exit.c */
void	free_map(char **map);
void	cleanup(t_game *game);
void	error_exit(t_game *game, char *msg);
int		close_game(t_game *game);

/* map_read.c */
void	read_map(t_game *game, char *path);

/* map_check.c */
void	check_map(t_game *game);

/* path_check.c */
void	check_path(t_game *game);

/* render.c */
void	load_images(t_game *game);
void	check_screen(t_game *game);
int		render(t_game *game);

/* move.c */
int		key_press(int keycode, t_game *game);

#endif
