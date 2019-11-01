/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:27:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/01 19:14:21 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void            valid_map(t_fdf *mlx, char *av)
{
	int     fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		output(2);
	read_map(mlx, fd);
	close(fd);
	mlx->map_y = count_words(mlx->line_map, '\n', '\0');
	mlx->map_x = count_words(mlx->line_map, ' ', '\n');
	parce_map(mlx);

}

void			parce_map(t_fdf *mlx)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(mlx->line_map, '\n');
	if (!(mlx->raw_map = (char **)malloc(sizeof(char *) * mlx->map_y)))
		output(6);
	if (!(mlx->map = (t_top **)malloc(sizeof(t_top *)
		* (mlx->map_y * mlx->map_x))))
		output(6);
	// while (tmp[++i])
	// {
	// 	if (!(mlx->raw_map[i] = (char *)malloc(sizeof(char) * mlx->map_x)))
	// 		output(6);
	// 	split_line(mlx, tmp[i]);
	// }
}

void			split_line(t_fdf *mlx, char *tmp)
{
	char	**tmp1;
	int		i;

	tmp1 = ft_strsplit(tmp, ' ');
	
}
