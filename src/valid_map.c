/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:27:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/03 21:36:31 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			valid_map(t_fdf *mlx, char *av)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		output(2);
	read_map(mlx, fd);
	close(fd);
	mlx->map_y = count_words(mlx->line_map, '\n', '\0');
	mlx->map_x = count_x(mlx->line_map);
	parce_map(mlx);
}

int				count_x(char *line)
{
	int		i;
	int		res;
	char	*tmp;

	i = -1;
	while (line[++i])
		if (ft_strchr("0123456789", line[i]))
			break ;
	tmp = ft_strdup(line + i);
	res = count_words(tmp, ' ', '\n');
	free(tmp);
	return (res);
}

void			parce_map(t_fdf *mlx)
{
	char	**tmp;
	int		i;
	int		k;

	i = -1;
	k = 0;
	if (mlx->map_x == 0 && mlx->map_y == 0)
		mlx->len = 1;
	else if (mlx->map_x == 0 && mlx->map_y != 0)
		mlx->len = mlx->map_y;
	else if (mlx->map_x != 0 && mlx->map_y == 0)
		mlx->len = mlx->map_x;
	else
		mlx->len = mlx->map_x * mlx->map_y;
	tmp = ft_strsplit(mlx->line_map, '\n');
	if (!(mlx->map = (t_top **)malloc(sizeof(t_top *) * mlx->len)))
		output(6);
	while (++i < mlx->len)
		if (!(mlx->map[i] = (t_top *)malloc(sizeof(t_top))))
			output(6);
	i = -1;
	while (tmp[++i])
		split_line(mlx, tmp, i, &k);
	split_free(tmp);
}

void			split_line(t_fdf *mlx, char **tmp, int i, int *k)
{
	char	**tmp1;
	int		j;
	int		spike;

	j = -1;
	spike = 0;
	tmp1 = ft_strsplit(tmp[i], ' ');
	while (tmp1[++j])
		fill_struct(mlx->map[(*k)++], tmp1[j], i, j);
	if (mlx->map_x == 0)
	{
		spike = 1;
		mlx->map_x = 1;
	}
	if (j != mlx->map_x)
		output(7);
	if (spike == 1)
		mlx->map_x = 0;
	split_free(tmp1);
}

void			fill_struct(t_top *map, char *tmp, int i, int j)
{
	map->sx = j;
	map->sy = i;
	map->x = j;
	map->y = i;
	if (!(ft_strchr(tmp, ',')))
	{
		map->sz = ft_atoi(tmp) * 0.4;
		map->z = ft_atoi(tmp) * 0.4;
		map->color = -1;
	}
	else
	{
		map->sz = ft_atoi(tmp) * 0.4;
		map->z = ft_atoi(tmp) * 0.4;
		map->color = ft_atoi_base(ft_strchr(tmp, 'x') + 1, 16);
	}
}
