/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_col.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:21:57 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/03 20:46:02 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			change_col_r(int key, t_fdf *mlx)
{
	if (key == 91)
	{
		if ((mlx->def_color >> 16) < 239)
			mlx->def_color += 0x0F0000;
		else
			mlx->def_color = mlx->def_color | 0xFF0000;
	}
	if (key == 89)
	{
		if ((mlx->def_color >> 16) > 15)
			mlx->def_color -= 0x0F0000;
		else
			mlx->def_color = mlx->def_color & 0x00FFFF;
	}
}

void			change_col_g(int key, t_fdf *mlx)
{
	if (key == 87)
	{
		if (((mlx->def_color >> 8) & 0xFF) < 239)
			mlx->def_color += 0xF00;
		else
			mlx->def_color = mlx->def_color | 0xFF00;
	}
	if (key == 86)
	{
		if (((mlx->def_color >> 8) & 0xFF) > 15)
			mlx->def_color -= 0xF00;
		else
			mlx->def_color = mlx->def_color & 0xFF00FF;
	}
}

void			change_col_b(int key, t_fdf *mlx)
{
	if (key == 84)
	{
		if ((mlx->def_color & 0xFF) < 239)
			mlx->def_color += 0xF;
		else
			mlx->def_color = mlx->def_color | 0xFF;
	}
	if (key == 83)
	{
		if ((mlx->def_color & 0xFF) > 15)
			mlx->def_color -= 0xF;
		else
			mlx->def_color = mlx->def_color & 0xFFFF00;
	}
}

void			change_color_fdf(t_fdf *f, int i)
{
	f->col_go = 0;
	f->col_go += (f->d0_col & 0xFF0000) +
			(r_fdf(f->d1_r * f->col_per * i) << 16);
	f->col_go += (f->d0_col & 0xFF00) +
			(r_fdf(f->d1_g * f->col_per * i) << 8);
	f->col_go += (f->d0_col & 0xFF) +
			r_fdf(f->d1_b * f->col_per * i);
}

void			color_delta(t_fdf *mlx)
{
	if (((mlx->d0_col & 0xFF0000) - (mlx->d1_col & 0xFF0000)) > 0)
		mlx->d1_r = -((mlx->d0_col >> 16) - (mlx->d1_col >> 16));
	else
		mlx->d1_r = (mlx->d1_col >> 16) - (mlx->d0_col >> 16);
	if (((mlx->d0_col & 0xFF00) - (mlx->d1_col & 0xFF00)) > 0)
		mlx->d1_g = -(((mlx->d0_col >> 8) & 0xFF) -
				((mlx->d1_col >> 8) & 0xFF));
	else
		mlx->d1_g = (((mlx->d1_col >> 8) & 0xFF) -
				((mlx->d0_col >> 8) & 0xFF));
	if (((mlx->d0_col & 0xFF) - (mlx->d1_col & 0xFF)) > 0)
		mlx->d1_b = -((mlx->d0_col & 0xFF) - (mlx->d1_col & 0xFF));
	else
		mlx->d1_b = (mlx->d1_col & 0xFF) - (mlx->d0_col & 0xFF);
	mlx->col_per = 1. / (double)(mlx->dots);
	mlx->col_go = mlx->d0_col;
}
