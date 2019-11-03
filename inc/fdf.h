/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:52:49 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/03 20:40:15 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 300000
# define X mlx->map[i]->x
# define Y mlx->map[i]->y
# define Z mlx->map[i]->z
# define SX mlx->map[i]->sx
# define SY mlx->map[i]->sy
# define SZ mlx->map[i]->sz
# define COLOR mlx->map[i]->color
# define BR_Y mlx->br_y
# define BR_X mlx->br_x
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "colors.h"
# include "mlx.h"

typedef struct	s_top
{
	double		sx;
	double		sy;
	double		sz;
	int			scolor;
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
	int			size_line;
	int			bpp;
	int			color;
	int			endian;
	int			len;
	int			width;
	int			height;
	int			d_scale;
	int			scale;
	int			mv_x;
	int			d_mv_x;
	int			delta_mv_x;
	int			mv_y;
	int			d_mv_y;
	int			delta_mv_y;
	int			br_x;
	int			br_y;
	int			x_0;
	int			y_0;
	int			x_1;
	int			y_1;
	int			dots;
	double		coff_z;
	double		d1_r;
	double		d1_g;
	double		d1_b;
	double		col_go;
	double		col_per;
	int			d0_col;
	int			d1_col;
	int			def_color;
	int			delta_x;
	int			delta_y;
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

void			valid_map(t_fdf *mlx, char *av);
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
void			xy(t_fdf *mlx);

/*
** window_init.c
*/

void			window_init(t_fdf *mlx);
void			display(t_fdf *mlx);
void			all_hooks(t_fdf *mlx);
void			workspace_scale(t_fdf *mlx);

/*
** draw_lines.c
*/

void			plot_line(t_fdf *mlx);
void			get_point(t_fdf *mlx, int i, int flag);
void			dots_count(t_fdf *mlx);
int				r_fdf(double x);
void			get_change_color(t_fdf *mlx, int i, int flag);

/*
** rotates.c
*/

void			rotate_x(int side, t_fdf *mlx);
void			rotate_y(int side, t_fdf *mlx);
void			rotate_z(int side, t_fdf *mlx);
void			horizontal(int side, t_fdf *mlx);
void			vertical(int side, t_fdf *mlx);
void			ft_front(t_fdf *mlx);

/*
** events.c
*/

void			all_hooks(t_fdf *mlx);
int				mouse_events(int ms, int x, int y, t_fdf *mlx);
int				keyboard_events1(int key, t_fdf *mlx);
int				keyboard_events2(int key, t_fdf *mlx);
int				get_out(void);

/*
** change_col.c
*/

void			change_col_r(int key, t_fdf *mlx);
void			change_col_g(int key, t_fdf *mlx);
void			change_col_b(int key, t_fdf *mlx);
void			color_delta(t_fdf *mlx);
void			change_color_fdf(t_fdf *f, int i);

#endif
