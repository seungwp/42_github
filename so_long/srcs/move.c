/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 20:49:49 by seukim            #+#    #+#             */
/*   Updated: 2026/10/10 20:50:17 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(int moves)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putchar_fd('\n', 1);
}

static void	move_player(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	next;

	nx = game->px + dx;
	ny = game->py + dy;
	next = game->map[ny][nx];
	if (next == '1')
		return ;
	game->px = nx;
	game->py = ny;
	game->moves++;
	print_moves(game->moves);
	if (next == 'C')
	{
		game->map[ny][nx] = '0';
		game->collect--;
	}
	if (next == 'E' && game->collect == 0)
	{
		ft_putendl_fd("You win!", 1);
		close_game(game);
	}
	render(game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}
