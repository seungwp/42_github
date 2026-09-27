/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seukim <seukim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 01:38:10 by seukim            #+#    #+#             */
/*   Updated: 2026/09/28 01:52:45 by seukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	key_press(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		close_window(param);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 640, 480, "so_long");
	if (!win)
		return (1);
	mlx_hook(win, 2, 1L << 0, key_press, NULL);
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_loop(mlx);
	return (0);
}
