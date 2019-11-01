/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:13:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/01 17:13:34 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			read_map(t_fdf *mlx, int fd)
{
	int		ret;
	char	buf[BUFF_SIZE];

	mlx->line_map = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			output(3);
		buf[ret] = '\0';
		check_buf(buf);
		ft_join_free((char **)&(mlx->line_map), buf);
	}
	if (ret == 0 && (!mlx->line_map))
		output(5);
	
}

void			check_buf(char *buf)
{
	int		i;

	i = -1;
	while (buf[++i])
	{

		if (!(ft_strchr("-0123456789 ,xabcdefABCDEF\n", buf[i])))
			output(4);
		if (buf[i] == ',')
			we_got_comma(buf, i);
		else if (buf[i] == 'x')
			we_got_x(buf, i);
	}
}

void			we_got_comma(char *buf, int i)
{
	int		j;

	j = i;
	while (--j != -1 && buf[j] != ' ')
		if (!(ft_strchr("-0123456789", buf[j])))
			output(4);
}

void			we_got_x(char *buf, int i)
{
	if (i - 1 == -1 && buf[i - 1] != '0')
		output(4);
}
