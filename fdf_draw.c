/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:22:04 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/31 18:22:05 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			create_map(t_coords *coords, t_image *image)
{
	t_coords	*start;
	int			i;

	i = 0;
	start = coords;
	while (start && start->next && start->x != image->current_x)
	{
		if (start->neighbour_x)
			put_line(start, image, (int)start->neighbour_x->x,
			(int)start->neighbour_x->y);
		if (start->neighbour_y)
			put_line(start, image, (int)start->neighbour_y->x,
			(int)start->neighbour_y->y);
		start = start->next;
		i++;
	}
	mlx_put_image_to_window(image->mlx_ptr,
							image->mlx_window, image->image_ptr, 0, 0);
}

void			put_image(t_coords *coords, int x, int y, int color)
{
	int			a;
	t_image		*image;

	image = coords->image;
	a = ((y * image->size_line) + (x * image->bpp));
	if (x >= 0 && x < W && y >= 0 && y < H && a <= H * image->size_line + H * 4)
	{
		image->data_buff[a] = (char)((image->green) ? image->green : color);
		image->data_buff[a + 1] = (char)image->red;
		image->data_buff[a + 2] = (char)image->blue;
	}
}

void			put_line_2(t_coords *coords, int *x0_y0, int *dx_dy, int *sx_sy)
{
	int			x_y_i[3];
	int			d;
	int			d1;
	int			d2;

	d = (dx_dy[0] << 1) - dx_dy[1];
	d1 = dx_dy[0] << 1;
	d2 = (dx_dy[0] - dx_dy[1]) << 1;
	put_image(coords, x0_y0[0], x0_y0[1], coords->color);
	x_y_i[0] = x0_y0[0];
	x_y_i[1] = x0_y0[1] + sx_sy[1];
	x_y_i[2] = 1;
	while (x_y_i[2] < dx_dy[1])
	{
		if (d > 0)
		{
			d += d2;
			x_y_i[0] += sx_sy[0];
		}
		else
			d += d1;
		x_y_i[2]++;
		x_y_i[1] += sx_sy[1];
		put_image(coords, x_y_i[0], x_y_i[1], coords->color);
	}
}

void			put_line_1(t_coords *coords, int *x0_y0, int *dx_dy, int *sx_sy)
{
	int			x_y_i[3];
	int			d;
	int			d1;
	int			d2;

	d = (dx_dy[1] << 1) - dx_dy[0];
	d1 = dx_dy[1] << 1;
	d2 = (dx_dy[1] - dx_dy[0]) << 1;
	put_image(coords, x0_y0[0], x0_y0[1], coords->color);
	x_y_i[0] = x0_y0[0] + sx_sy[0];
	x_y_i[1] = x0_y0[1];
	x_y_i[2] = 1;
	while (x_y_i[2] <= dx_dy[0])
	{
		if (d > 0)
		{
			d += d2;
			x_y_i[1] += sx_sy[1];
		}
		else
			d += d1;
		x_y_i[2]++;
		x_y_i[0] += sx_sy[0];
		put_image(coords, x_y_i[0], x_y_i[1], coords->color);
	}
}

void			put_line(t_coords *coords, t_image *image, int x1, int y1)
{
	int			x0_y0[2];
	int			dx_dy[2];
	int			sx_sy[2];

	x0_y0[0] = (int)coords->x;
	x0_y0[1] = (int)coords->y;
	dx_dy[0] = abs(x1 - x0_y0[0]);
	dx_dy[1] = abs(y1 - x0_y0[1]);
	sx_sy[0] = x1 >= x0_y0[0] ? 1 : -1;
	sx_sy[1] = y1 >= x0_y0[1] ? 1 : -1;
	coords->image = image;
	if (dx_dy[1] <= dx_dy[0])
		put_line_1(coords, x0_y0, dx_dy, sx_sy);
	else
		put_line_2(coords, x0_y0, dx_dy, sx_sy);
}
