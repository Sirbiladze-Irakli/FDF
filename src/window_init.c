/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:09:49 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/03 21:38:42 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			window_init(t_fdf *mlx)
{
	workspace_scale(mlx);
	mlx->ptr = mlx_init();
	if (!(mlx->win_ptr = mlx_new_window(mlx->ptr,
		mlx->width, mlx->height, "FDF")))
		output(8);
	mlx->image = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->i_data = mlx_get_data_addr(mlx->image, &mlx->bpp,
		&mlx->size_line, &mlx->endian);
	display(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->image, 0, 0);
	all_hooks(mlx);
	mlx_loop(mlx->ptr);
}

void			workspace_scale(t_fdf *mlx)
{
	mlx->width = 1500;
	mlx->height = 1200;
	mlx->delta_mv_x = 0;
	mlx->delta_mv_y = 0;
	mlx->coff_z = 1.0;
	if (mlx->map_x > mlx->map_y)
		mlx->scale = 1000 / (mlx->map_x - 1);
	else
		mlx->scale = 1000 / (mlx->map_y - 1);
	mlx->d_scale = mlx->scale;
	mlx->def_color = 0x99FFFF;
	mlx->mv_x = mlx->width / 2 - (mlx->map_x - 1) * mlx->scale / 2;
	mlx->d_mv_x = mlx->width / 2 - (mlx->map_x - 1) * mlx->scale / 2;
	mlx->delta_mv_x = mlx->mv_x - mlx->d_mv_x;
	mlx->mv_y = mlx->height / 2 - (mlx->map_y - 1) * mlx->scale / 2;
	mlx->d_mv_y = mlx->height / 2 - (mlx->map_y - 1) * mlx->scale / 2;
	mlx->delta_mv_y = mlx->mv_y - mlx->d_mv_y;
	return ;
}

void			display(t_fdf *mlx)
{
	int		i;

	i = -1;
	if (mlx->map_x == 0)
		mlx->map_x = 1;
	while (++i < mlx->len)
	{
		if (i >= 1 && (i % mlx->map_x))
		{
			get_point(mlx, i, 0);
			plot_line(mlx);
		}
		if (i >= mlx->map_x)
		{
			get_point(mlx, i, 1);
			plot_line(mlx);
		}
	}
}

void			ft_front(t_fdf *mlx)
{
	int		i;

	mlx->def_color = 0x99FFFF;
	i = -1;
	while (++i < mlx->len)
	{
		mlx->map[i]->x = mlx->map[i]->sx;
		mlx->map[i]->y = mlx->map[i]->sy;
		mlx->map[i]->z = mlx->map[i]->sz;
		mlx->map[i]->color = mlx->map[i]->color;
	}
	mlx->mv_x = mlx->d_mv_x;
	mlx->mv_y = mlx->d_mv_y;
	mlx->scale = mlx->d_scale;
	mlx->delta_mv_x = 0;
	mlx->delta_mv_y = 0;
}
