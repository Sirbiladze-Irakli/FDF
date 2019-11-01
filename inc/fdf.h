/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:52:49 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/01 19:12:20 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 300000
# include <fcntl.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "mlx.h"

typedef struct	s_top
{
	
	int			z;
	int			x;
	int			y;
}				t_top;


typedef struct	s_fdf
{
	t_top		**map;
	char		**raw_map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image;
	char		*i_data;
	char		*line_map;
	char		map_x;
	char		map_y;
}				t_fdf;


/*
** main.c
*/

int				main(int ac, char **av);
void			output(int var);
void			init_struct(t_fdf *mlx);

/*
** valid_map.c
*/

void            valid_map(t_fdf *mlx, char *av);
void			parce_map(t_fdf *mlx);
void			split_line(t_fdf *mlx, char *tmp);

/*
** read_map.c
*/

void			read_map(t_fdf *mlx, int fd);
void			check_buf(char *buf);
void			we_got_comma(char *buf, int i);
void			we_got_x(char *buf, int i);

/*
** tools.c
*/

int				count_words(char *line, char c, char end);

#endif