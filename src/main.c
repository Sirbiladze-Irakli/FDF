/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:04:39 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/01 19:04:38 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		output(int var)
{
	if (var == 1)
		write(1, "Usage ./fdf [File]\n", 26);
	else if (var == 2)
		write(1, "File descriptor asignment error.\n", 33);
	else if (var == 3)
		write(1, "Error reading file.\n", 20);
	else if (var == 4)
		write(1, "Invalid symbol.\n", 17);
	else if (var == 5)
		write(1, "Empty file\n", 17);
	else if (var == 6)
		write(1, "could not allocate memory\n", 26);
	exit (0);
}

void		init_struct(t_fdf *mlx)
{
	mlx->map_x = 0;
	mlx->map_y = 0;
	return ;
}

int			main(int ac, char **av)
{
	t_fdf		mlx;

	init_struct(&mlx);
	if (ac == 2)
	{
		valid_map(&mlx, av[1]);
		// mlx.mlx_ptr = mlx_init();
		// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 750, "The Best FDF");
		// mlx_loop(mlx.mlx_ptr);
		// mlx_key_hook(mlx.win_ptr, )
		output(0);
	}
	output(1);
}
