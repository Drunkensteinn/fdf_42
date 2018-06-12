/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move_centralize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:07:11 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/11 20:07:13 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			centralize(t_image *image, t_coords *coords)
{
	double		a1;
	double		a2;
	double		b1;
	double		b2;

	move_out(coords->image, coords);
	a1 = W / 2;
	a2 = H / 2;
	b1 = ((image->current_x - 1) / 2) * INCR;
	b2 = (image->current_y / 2) * INCR;
	a1 = fabs(a1 - b1 / (2 * INCR));
	a2 = fabs(a2 - b2 / (2 * INCR));
	while (coords)
	{
		coords->x += (a1);
		coords->y += (a2);
		coords = coords->next;
	}
}

void			move(t_image *image, t_coords *coords)
{
	double		a1;
	double		a2;
	double		b1;
	double		b2;

	a1 = W / 2;
	a2 = H / 2;
	b1 = ((image->current_x - 1) / 2) * INCR;
	b2 = (image->current_y / 2) * INCR;
	a1 = fabs(a1 - b1);
	a2 = fabs(a2 - b2);
	while (coords)
	{
		coords->x += a1;
		coords->y += a2;
		coords = coords->next;
	}
}

void			move_out(t_image *image, t_coords *coords)
{
	double		a1;
	double		a2;
	double		b1;
	double		b2;

	a1 = W / 2;
	a2 = H / 2;
	b1 = ((image->current_x - 1) / 2) * INCR;
	b2 = (image->current_y / 2) * INCR;
	a1 = fabs(a1 - b1 / (2 * INCR));
	a2 = fabs(a2 - b2 / (2 * INCR));
	a1 = fabs(a1 + (double)image->move_x);
	a2 = fabs(a2 + (double)image->move_y);
	while (coords)
	{
		coords->x -= a1;
		coords->y -= a2;
		coords = coords->next;
	}
}

void			move_2(t_image *image, t_coords *coords)
{
	double		a1;
	double		a2;
	double		b1;
	double		b2;

	a1 = W / 2;
	a2 = H / 2;
	b1 = ((image->current_x - 1) / 2) * INCR;
	b2 = ((image->current_y) / 2) * INCR;
	a1 = fabs(a1 - b1 / (2 * INCR));
	a2 = fabs(a2 - b2 / (2 * INCR));
	a1 = fabs(a1 + (double)image->move_x);
	a2 = fabs(a2 + (double)image->move_y);
	while (coords)
	{
		coords->x = coords->x + (a1);
		coords->y = coords->y + (a2);
		coords = coords->next;
	}
}

void			make_it_free(t_coords *coords)
{
	t_coords	*tmp;

	tmp = NULL;
	while (coords)
	{
		tmp = (coords);
		coords = coords->next;
		free(tmp);
		tmp = NULL;
	}
}
