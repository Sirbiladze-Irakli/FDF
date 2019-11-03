/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:18:24 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/03 20:44:02 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			all_hooks(t_fdf *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, keyboard_events1, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_events, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, get_out, mlx);
}

int				mouse_events(int ms, int x, int y, t_fdf *mlx)
{
	if (ms == 4)
	{
		mlx->delta_mv_x -= (x - 500) / 44;
		mlx->delta_mv_y -= (y - 500) / 44;
		mlx->scale = (mlx->scale > 50) ? mlx->scale + 15 : mlx->scale + 1;
		mlx->mv_x = ((mlx->width / 2) - (mlx->map_x - 1) * mlx->scale / 2) +
		mlx->delta_mv_x;
		mlx->mv_y = ((mlx->height / 2) - (mlx->map_y - 1) * mlx->scale / 2) +
		mlx->delta_mv_y;
	}
	if (ms == 5 && mlx->scale > 1)
	{
		mlx->delta_mv_x += (x - 500) / 44;
		mlx->delta_mv_y += (y - 500) / 44;
		mlx->scale = (mlx->scale > 50) ? mlx->scale - 15 : mlx->scale - 1;
		mlx->mv_x = ((mlx->width / 2) - (mlx->map_x - 1) * mlx->scale / 2)
			+ mlx->delta_mv_x;
		mlx->mv_y = ((mlx->height / 2) - (mlx->map_y - 1) * mlx->scale / 2)
			+ mlx->delta_mv_y;
	}
	draw(mlx);
	return (0);
}

int				keyboard_events1(int key, t_fdf *mlx)
{
	if (key == 15)
		ft_front(mlx);
	if (key == 53)
		get_out();
	if (key == 13)
		rotate_x(1, mlx);
	if (key == 1)
		rotate_x(0, mlx);
	if (key == 2)
		rotate_y(0, mlx);
	if (key == 0)
		rotate_y(1, mlx);
	if (key == 12)
		rotate_z(1, mlx);
	if (key == 14)
		rotate_z(0, mlx);
	keyboard_events2(key, mlx);
	change_col_r(key, mlx);
	change_col_g(key, mlx);
	change_col_b(key, mlx);
	draw(mlx);
	return (0);
}

int				keyboard_events2(int key, t_fdf *mlx)
{
	if (key == 34)
	{
		ft_front(mlx);
		rotate_x(1, mlx);
		rotate_x(1, mlx);
		rotate_x(1, mlx);
		rotate_y(1, mlx);
		rotate_y(1, mlx);
		rotate_y(1, mlx);
		rotate_z(0, mlx);
		rotate_z(0, mlx);
		rotate_z(0, mlx);
	}
	if (key == 124)
		horizontal(0, mlx);
	if (key == 123)
		horizontal(1, mlx);
	if (key == 126)
		vertical(1, mlx);
	if (key == 125)
		vertical(0, mlx);
	return (0);
}

int				get_out(void)
{
	exit(0);
}
