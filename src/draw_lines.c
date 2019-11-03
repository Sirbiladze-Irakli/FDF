/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:09:43 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/03 20:41:12 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			get_point(t_fdf *mlx, int i, int flag)
{
	if (flag == 0)
	{
		mlx->x_0 = (mlx->map[i - 1]->x) * mlx->scale + mlx->mv_x;
		mlx->y_0 = (mlx->map[i - 1]->y) * mlx->scale + mlx->mv_y;
		mlx->x_1 = (X) * mlx->scale + mlx->mv_x;
		mlx->y_1 = (Y) * mlx->scale + mlx->mv_y;
		get_change_color(mlx, i, flag);
	}
	if (flag == 1)
	{
		mlx->x_0 = (mlx->map[i - mlx->map_x]->x) * mlx->scale + mlx->mv_x;
		mlx->y_0 = (mlx->map[i - mlx->map_x]->y) * mlx->scale + mlx->mv_y;
		mlx->x_1 = (X) * mlx->scale + mlx->mv_x;
		mlx->y_1 = (Y) * mlx->scale + mlx->mv_y;
		get_change_color(mlx, i, flag);
	}
}

void			get_change_color(t_fdf *mlx, int i, int flag)
{
	if (mlx->map[i]->color != -1)
		mlx->d1_col = mlx->map[i]->color;
	else
		mlx->d1_col = mlx->def_color;
	if (flag == 0)
	{
		if (mlx->map[i - 1]->color != -1)
			mlx->d0_col = mlx->map[i - 1]->color;
		else
			mlx->d0_col = mlx->def_color;
	}
	else if (flag == 1)
	{
		if (mlx->map[i - mlx->map_x]->color != -1)
			mlx->d0_col = mlx->map[i - mlx->map_x]->color;
		else
			mlx->d0_col = mlx->def_color;
	}
}

void			plot_line(t_fdf *mlx)
{
	int		i;

	i = -1;
	xy(mlx);
	dots_count(mlx);
	while (BR_X != mlx->x_1 || BR_Y != mlx->y_1)
	{
		if (BR_X < mlx->width && BR_X > 0 && BR_Y < mlx->height && BR_Y > 0)
		{
			*(int *)(mlx->i_data +
			((BR_X + BR_Y * mlx->width) * 4)) = r_fdf(mlx->col_go);
			change_color_fdf(mlx, ++i);
		}
		mlx->error2 = mlx->error * 2;
		if (mlx->error2 < mlx->delta_x)
		{
			mlx->error += mlx->delta_x;
			BR_Y += mlx->sign_y;
		}
		if (mlx->error2 > -(mlx->delta_y))
		{
			mlx->error -= mlx->delta_y;
			BR_X += mlx->sign_x;
		}
	}
}

int				r_fdf(double x)
{
	int	a;

	a = (int)x;
	x = x - a;
	if (x > 0)
	{
		if (x > 0.5)
			return (a + 1);
		else
			return (a);
	}
	if (x < -0.5)
		return (a - 1);
	return (a);
}

void			dots_count(t_fdf *mlx)
{
	mlx->dots = 0;
	while (mlx->d0_col != mlx->d1_col &&
		(mlx->br_x != mlx->x_1 || mlx->br_y != mlx->y_1))
	{
		if (mlx->br_x < mlx->width && mlx->br_x > 0 && mlx->br_y < mlx->height
			&& mlx->br_y > 0)
			mlx->dots++;
		mlx->error2 = mlx->error * 2;
		if (mlx->error2 < mlx->delta_x)
		{
			mlx->error += mlx->delta_x;
			mlx->br_y += mlx->sign_y;
		}
		if (mlx->error2 > -(mlx->delta_y))
		{
			mlx->error -= mlx->delta_y;
			mlx->br_x += mlx->sign_x;
		}
	}
	if (mlx->dots == 0)
		mlx->dots++;
	xy(mlx);
	color_delta(mlx);
}
