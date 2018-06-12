/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:22:34 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/31 18:22:35 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# define W 1200
# define H 800
# define INCR ((H / 2) / image->current_y)

typedef struct		s_coords
{
	double			x;
	double			y;
	double			z;
	int				color;
	struct s_image	*image;
	struct s_coords	*neighbour_x;
	struct s_coords	*neighbour_y;
	struct s_coords	*next;
}					t_coords;

typedef struct		s_image
{
	char			*data_buff;
	void			*mlx_ptr;
	void			*mlx_window;
	void			*image_ptr;
	int				bpp;
	int				size_line;
	int				endian;
	int				current_x;
	int				current_y;
	int				move_x;
	int				move_y;
	int				move_x_r;
	int				move_y_r;
	int				red;
	int				green;
	int				blue;
}					t_image;

void				parser_f(int *arr, char *line, int *i, t_coords *coords);
void				make_it_free(t_coords *coords);
void				centralize(t_image *image, t_coords *coords);
void				start_projection(t_coords **coords, t_image *image);
void				zoom_minus(t_coords *coords);
void				zoom_plus(t_coords *coords);
void				zero(t_image *image);
void				put_message(t_image *image);
void				move_2(t_image *image, t_coords *coords);
void				move(t_image *image, t_coords *coords);
void				rotation_z(t_coords *coords, double z);
void				rotation_x(t_coords *coords, double x);
void				rotation_y(t_coords *coords, double y);
void				move_out(t_image *image, t_coords *coords);
int					keys(int keycode, t_coords *coords);
void				keys_1(int keycode, t_coords *coords);
void				keys_2(int keycode, t_coords *coords);
void				keys_3(int keycode, t_coords *coords);
void				keys_4(int keycode, t_coords *coords);
void				parse_final(t_coords **coords, t_image *image);
void				parser_list_neibour(t_coords **coords, t_image *image);
int					parse_list_neib_2(t_coords **head_x,
					t_coords **head_y, t_image *image);
int					validator(char *line);
void				initialise(t_image *tmp);
int					read_from(int fd, t_coords **coords, t_image *image);
void				put_image(t_coords *coords, int x, int y, int color);
void				window_initialize(t_image *image, t_coords **coords);
void				create_map(t_coords *coords, t_image *image);
void				parser_list(const int *crd, int color, t_coords **coords);
void				parser_line(char *line, t_coords **coords, int *k);
void				put_line(t_coords *coords, t_image *image, int x0, int y0);
void				put_line_1(t_coords *coords,
					int *x0_y0, int *dx_dy, int *sx_sy);
void				put_line_2(t_coords *coords,
					int *x0_y0, int *dx_dy, int *sx_sy);

#endif
