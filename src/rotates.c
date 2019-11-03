/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:58:26 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/03 20:45:25 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_x(int side, t_fdf *mlx)
{
	int		i;
	double	n;
	double	y;

	n = (side == 0) ? 0.17453292519 : -0.17453292519;
	i = -1;
	while (++i < mlx->len)
	{
		y = Y - mlx->map_y / 2;
		Y = mlx->map_y / 2 + y * cos(n) + Z * sin(n);
		Z = -y * sin(n) + Z * cos(n);
	}
}

void			rotate_y(int side, t_fdf *mlx)
{
	int		i;
	double	n;
	double	x;

	n = (side == 0) ? 0.17453292519 : -0.17453292519;
	i = -1;
	while (++i < mlx->len)
	{
		x = X - mlx->map_x / 2;
		X = mlx->map_x / 2 + x * cos(n) + Z * sin(n);
		Z = -x * sin(n) + Z * cos(n);
	}
}

void			rotate_z(int side, t_fdf *mlx)
{
	int		i;
	double	n;
	double	x;
	double	y;

	n = (side == 0) ? 0.17453292519 : -0.17453292519;
	i = -1;
	while (++i < mlx->len)
	{
		x = X - mlx->map_x / 2;
		y = Y - mlx->map_y / 2;
		X = mlx->map_x / 2 + x * cos(n) - y * sin(n);
		Y = mlx->map_y / 2 + x * sin(n) + y * cos(n);
	}
}

void			horizontal(int side, t_fdf *mlx)
{
	int		n;

	n = (side == 0) ? 10 : -10;
	mlx->mv_x += n;
	mlx->delta_mv_x += n;
}

void			vertical(int side, t_fdf *mlx)
{
	int		n;

	n = (side == 0) ? 10 : -10;
	mlx->mv_y += n;
	mlx->delta_mv_y += n;
}
