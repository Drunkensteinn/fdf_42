/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:24:57 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/11 20:24:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline int			keys(int keycode, t_coords *coords)
{
	t_coords		*tmp;
	t_image			*tmp_1;

	tmp_1 = (coords)->image;
	tmp = coords;
	keys_1(keycode, coords);
	keys_2(keycode, coords);
	keys_3(keycode, coords);
	keys_4(keycode, coords);
	ft_bzero(tmp_1->data_buff, W * H * 4);
	move_2(coords->image, coords);
	mlx_clear_window(tmp_1->mlx_ptr, tmp_1->mlx_window);
	create_map(tmp, (coords)->image);
	put_message((coords)->image);
	ft_bzero(tmp_1->data_buff, W * H * 4);
	move_out(coords->image, coords);
	return (1);
}

inline void			keys_1(int keycode, t_coords *coords)
{
	t_coords		*tmp;
	t_image			*tmp_1;

	tmp_1 = (coords)->image;
	tmp = coords;
	if (keycode == 53)
	{
		free(tmp_1->mlx_ptr);
		free(tmp_1->data_buff);
		make_it_free(coords);
		exit(0);
	}
	else if (keycode == 88)
		rotation_z(tmp, 3);
	else if (keycode == 85)
		rotation_z(tmp, -3);
	else if (keycode == 87)
		rotation_y(tmp, 3);
	else if (keycode == 84)
		rotation_y(tmp, -3);
	else if (keycode == 86)
		rotation_x(tmp, 3);
	else if (keycode == 83)
		rotation_x(tmp, -3);
}

inline void			keys_2(int keycode, t_coords *coords)
{
	t_image			*tmp_1;

	tmp_1 = (coords)->image;
	if (keycode == 126)
	{
		tmp_1->move_y += -10;
		tmp_1->move_x += 0;
		tmp_1->move_y_r += 10;
		tmp_1->move_x_r += 0;
	}
	else if (keycode == 125)
	{
		tmp_1->move_y += 10;
		tmp_1->move_x += 0;
		tmp_1->move_y_r += -10;
		tmp_1->move_x_r += 0;
	}
	else if (keycode == 123)
	{
		tmp_1->move_y += 0;
		tmp_1->move_x += -10;
		tmp_1->move_y_r += 0;
		tmp_1->move_x_r += 10;
	}
}

inline void			keys_3(int keycode, t_coords *coords)
{
	t_image			*tmp_1;

	tmp_1 = (coords)->image;
	if (keycode == 124)
	{
		tmp_1->move_y += 0;
		tmp_1->move_x += 10;
		tmp_1->move_y_r += 0;
		tmp_1->move_x_r += -10;
	}
	else if (keycode == 5)
	{
		tmp_1->green = 1;
		tmp_1->blue = 0;
		tmp_1->red = 255;
	}
	else if (keycode == 11)
	{
		tmp_1->green = 0;
		tmp_1->blue = 1;
		tmp_1->red = 0;
	}
}

inline void			keys_4(int keycode, t_coords *coords)
{
	t_image			*tmp_1;

	tmp_1 = (coords)->image;
	if (keycode == 15)
	{
		tmp_1->green = 1;
		tmp_1->blue = 255;
		tmp_1->red = 0;
	}
	else if (keycode == 69)
		zoom_plus(coords);
	else if (keycode == 78)
		zoom_minus(coords);
	else if (keycode == 49)
		centralize(coords->image, coords);
}
