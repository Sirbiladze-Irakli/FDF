/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:09:43 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/02 20:26:12 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			get_point(t_fdf *mlx, int i, int flag)
{
	if (flag == 0)
	{
		mlx->x_0 = (X - 1) * mlx->scale + mlx->mv_x + mlx->delta_mv_x;
		mlx->y_0 = (Y) * mlx->scale + mlx->mv_y + mlx->delta_mv_y;
		mlx->x_1 = (X) * mlx->scale + mlx->mv_x + mlx->delta_mv_x;
		mlx->y_1 = (Y) * mlx->scale + mlx->mv_y + mlx->delta_mv_y;
        mlx->color = COLOR;
	}
	if (flag == 1)
	{
		mlx->x_0 = (X) * mlx->scale + mlx->mv_x + mlx->delta_mv_x;
		mlx->y_0 = (Y - 1) * mlx->scale + mlx->mv_y + mlx->delta_mv_y;
		mlx->x_1 = (X) * mlx->scale + mlx->mv_x + mlx->delta_mv_x;
		mlx->y_1 = (Y) * mlx->scale + mlx->mv_y + mlx->delta_mv_y;        
        mlx->color = COLOR;
	}
	
	
}

void			plot_line(t_fdf *mlx)
{
	xy(mlx);
	while (mlx->br_x != mlx->x_1 || mlx->br_y != mlx->y_1)
	{
		*(int *)(mlx->i_data + ((mlx->br_x + mlx->br_y * mlx->width) * 4)) = mlx->color;
			// ft_get_color(mlx);
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
}

void			xy(t_fdf *mlx)
{
	mlx->delta_x = ft_abs(mlx->x_1 - mlx->x_0);
	mlx->delta_y = ft_abs(mlx->y_1 - mlx->y_0);
	mlx->sign_x = mlx->x_0 < mlx->x_1 ? 1 : -1;
	mlx->sign_y = mlx->y_0 < mlx->y_1 ? 1 : -1;
	mlx->error = mlx->delta_x - mlx->delta_y;
	mlx->br_y = mlx->y_0;
	mlx->br_x = mlx->x_0;
}

