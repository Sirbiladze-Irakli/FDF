/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:52:49 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/02 20:35:52 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 300000
# define X mlx->map[i]->x
# define Y mlx->map[i]->y
# define Z mlx->map[i]->z
# define COLOR mlx->map[i]->color
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "colors.h"
# include "mlx.h"

typedef struct	s_top
{
	
	double		z;
	double		x;
	double		y;
	int			color;
}				t_top;


typedef struct	s_fdf
{
	t_top		**map;
	void		*ptr;
	void		*win_ptr;
	void		*image;
	char		*i_data;
	char		*line_map;
	int 		size_line;
	int			bpp;
	int			color;
	int			endian;
	int			len;
	int			width;
	int			height;
	int			scale;
	int			mv_x;
	int			mv_y;
	int			br_x;
	int			br_y;
	int			x_0;
	int			y_0;
	int			x_1;
	int			y_1;
	int			delta_x;
	int			delta_y;
	int			delta_mv_x;
	int			delta_mv_y;
	int			sign_x;
	int			sign_y;
	int			map_x;
	int			map_y;
	int			error;
	int			error2;
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
int				count_x(char *line);
void			parce_map(t_fdf *mlx);
void			split_line(t_fdf *mlx, char **tmp, int i, int *k);
void			fill_struct(t_top *map, char *tmp, int i, int j);

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
void			split_free(char **tmp);
int				ft_abs(int number);
void			draw(t_fdf *mlx);

/*
** window_init.c
*/

void            window_init(t_fdf *mlx);
void			display(t_fdf *mlx);
void			all_hooks(t_fdf *mlx);
void			workspace_scale(t_fdf *mlx);
int				mouse_events(t_fdf *mlx);
int				keyboard_events(int key, t_fdf *mlx);
int				get_out(void);

/*
** draw_lines.c
*/

void			plot_line(t_fdf *mlx);
void			xy(t_fdf *mlx);
void			get_point(t_fdf *mlx, int i, int flag);

/*
** rotates.c
*/

void			rotate_x(int side, t_fdf *mlx);
void			rotate_y(int side, t_fdf *mlx);
void			rotate_z(int side, t_fdf *mlx);
void			horizontal(int side, t_fdf *mlx);
void			vertical(int side, t_fdf *mlx);

#endif