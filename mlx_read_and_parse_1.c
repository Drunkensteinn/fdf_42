/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_read_and_parse_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 20:38:44 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/11 20:38:45 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			parser_list_neibour(t_coords **coords, t_image *image)
{
	t_coords	*head_x;
	t_coords	*head_y;
	int			counts_x;
	double		current[2];
	int			a;

	head_x = *coords;
	head_y = *coords;
	counts_x = image->current_x;
	a = INCR;
	while (head_x && head_x->next && head_x->x != counts_x * a)
	{
		current[0] = head_y->y;
		if (parse_list_neib_2(&head_x, &head_y, image))
			continue;
		while (head_y && head_y->y == current[0])
			head_y = head_y->next;
		while (head_y && head_y->x < head_x->x)
			head_y = head_y->next;
		head_x->neighbour_y = head_y;
		head_x = head_x->next;
		head_y = head_x;
	}
}

int				parse_list_neib_2(t_coords **head_x,
				t_coords **head_y, t_image *image)
{
	int			counts_x;
	double		current;
	int			a;

	a = INCR;
	counts_x = image->current_x;
	current = (*head_y)->y;
	if ((*head_x)->x != (counts_x - 1) * a)
		(*head_x)->neighbour_x = (*head_x)->next;
	else if ((*head_x)->x == (counts_x - 1) * a)
	{
		while ((*head_y)->y == current)
			(*head_y) = (*head_y)->next;
		while ((*head_y)->x < (*head_x)->x)
			(*head_y) = (*head_y)->next;
		(*head_x)->neighbour_y = (*head_y);
		(*head_x) = (*head_x)->next;
		(*head_y) = (*head_x);
		return (1);
	}
	return (0);
}

void			parser_list(const int *crd, int color, t_coords **coords)
{
	t_coords	*tmp;

	if ((*coords) == NULL)
	{
		*coords = (t_coords *)malloc(sizeof(t_coords));
		(*coords)->x = crd[0];
		(*coords)->y = crd[1];
		(*coords)->z = crd[2];
		(*coords)->color = color;
		(*coords)->next = NULL;
		return ;
	}
	tmp = (*coords);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_coords *)malloc(sizeof(t_coords));
	tmp = tmp->next;
	tmp->x = crd[0];
	tmp->y = crd[1];
	tmp->z = crd[2];
	tmp->color = color;
	tmp->neighbour_x = NULL;
	tmp->neighbour_y = NULL;
	tmp->next = NULL;
}

void			parse_final(t_coords **coords, t_image *image)
{
	t_coords	*tmp;
	double		x;
	double		y;
	double		z;

	tmp = *coords;
	while (tmp)
	{
		x = tmp->x * INCR;
		tmp->x = x;
		y = tmp->y * INCR;
		tmp->y = y;
		z = tmp->z * INCR;
		tmp->z = z;
		tmp = tmp->next;
	}
}
