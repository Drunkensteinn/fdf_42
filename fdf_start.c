/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:22:25 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/31 18:22:26 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			zero(t_image *image)
{
	image->move_x = 0;
	image->move_y = 0;
	image->move_x_r = 0;
	image->move_y_r = 0;
}

void			initialise(t_image *tmp)
{
	tmp->mlx_ptr = 0;
	tmp->mlx_window = 0;
	tmp->data_buff = NULL;
	tmp->size_line = 0;
	tmp->endian = 0;
	tmp->red = 0;
	tmp->green = 0;
	tmp->blue = 0;
}

void			start_projection(t_coords **coords, t_image *image)
{
	move(image, *coords);
	move_out(image, *coords);
	rotation_x(*coords, 2);
	rotation_y(*coords, -5);
	rotation_z(*coords, 40);
	move_2(image, *coords);
	create_map(*coords, image);
	put_message(image);
	move_out(image, *coords);
}

void			window_initialize(t_image *image, t_coords **coords)
{
	image->mlx_ptr = mlx_init();
	image->mlx_window = mlx_new_window(image->mlx_ptr, W, H, "fdf");
	image->image_ptr = mlx_new_image(image->mlx_ptr, W, H);
	image->data_buff = mlx_get_data_addr(image->image_ptr,
	&image->bpp, &image->size_line, &image->endian);
	image->bpp /= 8;
	image->move_y = 0;
	image->move_x = 0;
	(*coords)->image = image;
	start_projection(coords, image);
	mlx_hook(image->mlx_window, 2, 5, keys, *coords);
	mlx_loop(image->mlx_ptr);
}

void			put_message(t_image *image)
{
	mlx_string_put(image->mlx_ptr, image->mlx_window, 0, 0,
	0xe52845, "\t\tHey YOU!,\t\t\n Some tips for you : ");
	mlx_string_put(image->mlx_ptr, image->mlx_window, 0, 20,
	0x40e0d0, "Move up: '^',Move left: '<', Move right: '>', Move down :"
	"'\\/' (im sorry, cant inteprette unicode)");
	mlx_string_put(image->mlx_ptr, image->mlx_window, 0, 40, 0xffffff,
	"Rotate X - num 4 / 1, Rotate Y - num 5 / 2,"
	"Rotate Z - num 6 / 3; Zoom '+' and '-' ;");
	mlx_string_put(image->mlx_ptr, image->mlx_window, 0,
	60, 0x40e0d0, "Red - 'R', Green - 'G', Blue - 'B'");
	mlx_do_sync(image->mlx_ptr);
}
