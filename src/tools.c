/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:25:57 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/02 21:05:32 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_words(char *line, char c, char end)
{
	int		i;
	int		count;

	i = -1;
	count = 1;
	if (!(ft_strchr(line, c)))
		return (0);
	while (line[++i] != end && line[i])
		if (line[i] == c && line[i + 1] != c
		&& line[i + 1] != '\0' && line[i + 1] != '\n')
			count++;
	return (count);
}

void		split_free(char **tmp)
{
	int		i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

int			ft_abs(int number)
{
	return (number > 0 ? number : -number);
}

void		draw(t_fdf *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win_ptr);
	ft_bzero(mlx->i_data, mlx->height * mlx->width * 4);
	display(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->image, 0, 0);
}
