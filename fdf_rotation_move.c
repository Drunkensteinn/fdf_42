/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:05:03 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/11 20:05:06 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotation_z(t_coords *coords, double z)
{
	t_coords	*tmp;
	double		s[3];

	ft_bzero_int((int *)s, 3);
	tmp = coords;
	while (tmp)
	{
		s[0] = tmp->x;
		s[1] = tmp->y;
		tmp->x = s[0] * cos((z * M_PI) / 180) - s[1] * sin((z * M_PI) / 180);
		tmp->y = s[0] * sin((z * M_PI) / 180) + s[1] * cos((z * M_PI) / 180);
		tmp = tmp->next;
	}
}

void			rotation_y(t_coords *coords, double y)
{
	t_coords	*tmp;
	double		s[3];

	ft_bzero_int((int *)s, 3);
	tmp = coords;
	while (tmp)
	{
		s[0] = tmp->z;
		s[1] = tmp->x;
		tmp->z = s[0] * cos((y * M_PI) / 180) - s[1] * sin((y * M_PI) / 180);
		tmp->x = s[0] * sin((y * M_PI) / 180) + s[1] * cos((y * M_PI) / 180);
		tmp = tmp->next;
	}
}

void			rotation_x(t_coords *coords, double x)
{
	t_coords	*tmp;
	double		s[3];

	ft_bzero_int((int *)s, 3);
	tmp = coords;
	while (tmp)
	{
		s[0] = tmp->y;
		s[1] = tmp->z;
		tmp->y = s[0] * cos((x * M_PI) / 180) - s[1] * sin((x * M_PI) / 180);
		tmp->z = s[0] * sin((x * M_PI) / 180) + s[1] * cos((x * M_PI) / 180);
		tmp = tmp->next;
	}
}

void			zoom_plus(t_coords *coords)
{
	while (coords)
	{
		coords->x *= 1.1;
		coords->y *= 1.1;
		coords->z *= 1.1;
		coords = coords->next;
	}
}

void			zoom_minus(t_coords *coords)
{
	while (coords)
	{
		coords->x /= 1.1;
		coords->y /= 1.1;
		coords->z /= 1.1;
		coords = coords->next;
	}
}
