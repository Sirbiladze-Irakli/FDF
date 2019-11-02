/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:09:49 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/02 21:05:41 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void            window_init(t_fdf *mlx)
{
	mlx->ptr = mlx_init();
	workspace_scale(mlx);
	if (!(mlx->win_ptr = mlx_new_window(mlx->ptr,
		mlx->width , mlx->height, "FDF")))
		output(8);
	mlx->image = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->i_data = mlx_get_data_addr(mlx->image, &mlx->bpp,
		&mlx->size_line, &mlx->endian);
	display(mlx);
	all_hooks(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->image, 0, 0);
	mlx_loop(mlx->ptr);
}

void			all_hooks(t_fdf *mlx)
{
	mlx_hook(mlx->win_ptr, 2, 0, keyboard_events, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_events, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, get_out, mlx);
}

int				mouse_events(t_fdf *mlx)
{
	return (0);
}

int				keyboard_events(int key, t_fdf *mlx)
{
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
	if (key == 124)
		horizontal(0, mlx);
	if (key == 123)
		horizontal(1, mlx);
	if (key == 126)
		vertical(1, mlx);
	if (key == 125)
		vertical(0, mlx);
	draw(mlx);
	return (0);
}


// int		ft_keys(int key, t_fdf *f)
// {
// 	standart_key(key, f);
// 	if (key == 13)
// 		rotate_x(1, f);
// 	if (key == 1)
// 		rotate_x(0, f);
// 	if (key == 2)
// 		rotate_y(0, f);
// 	if (key == 0)
// 		rotate_y(1, f);
	// if (key == 12)
	// 	rotate_z(1, f);
	// if (key == 14)
	// 	rotate_z(0, f);
	// if (key == 124)
	// 	horizon(0, f);
	// if (key == 123)
	// 	horizon(1, f);
	// if (key == 126)
	// 	vertical(1, f);
	// if (key == 125)
	// 	vertical(0, f);
// 	draw(f);
// 	return (0);
// }


int				get_out(void)
{
	exit (0);
}

void			workspace_scale(t_fdf *mlx)
{
	mlx->width = 1500;
	mlx->height = 1200;
	mlx->delta_mv_x = 0;
	mlx->delta_mv_y = 0;
	if (mlx->map_x > mlx->map_y)
		mlx->scale = 1000 / (mlx->map_x - 1);
	else
		mlx->scale = 1000 / (mlx->map_y - 1);
	mlx->mv_x = mlx->width / 2 - (mlx->map_x - 1) / 2 * mlx->scale;
	mlx->mv_y = mlx->height / 2 - (mlx->map_y - 1) / 2 * mlx->scale;
	// printf("%d mv_x\n", mlx->mv_x);
	// printf("%d mv_y\n", mlx->mv_y);
	// printf("%d x\n", mlx->map_x);
	// printf("%d y\n", mlx->map_y);
	// printf("%d scale\n", mlx->scale);
	return ;
}

void			display(t_fdf *mlx)
{
	int		i;

	i = -1;
	while (++i < mlx->len)
	{
		// *(int *)(mlx->i_data + (X * mlx->scale + mlx->mv_x +
		// (Y * mlx->scale + mlx->mv_y) * mlx->width) * 4) = COLOR;
		if (X > 0)
		{
			get_point(mlx, i, 0);
			plot_line(mlx);
		}
		if (Y > 0)
		{
			get_point(mlx, i, 1);
			plot_line(mlx);
		}
		// printf("%f x\n", X);
		// printf("%f x\n", Y);
	}
		
		// mlx_pixel_put(mlx->ptr, mlx->win_ptr, X, Y, COLOR);
	
}

