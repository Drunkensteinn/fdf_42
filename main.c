/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:38:52 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/11 21:38:53 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_coords	*coord_head;
	t_image		image;
	int			fd;

	if (argc == 2)
	{
		initialise(&image);
		fd = open(argv[1], O_RDONLY);
		if (fd <= 0)
		{
			perror("error");
			exit(1);
		}
		zero(&image);
		read_from(fd, &coord_head, &image);
		parse_final(&coord_head, &image);
		parser_list_neibour(&coord_head, &image);
		window_initialize(&image, &coord_head);
		close(fd);
	}
	else
		ft_putstr("Usage: ./fdf <filename>\n");
	return (0);
}
