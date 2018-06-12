/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_read_and_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 22:03:47 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/31 22:03:51 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				read_from(int fd, t_coords **coords, t_image *image)
{
	char		*line;
	static int	k;
	static int	count;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (count == 0)
			count = validator(line);
		else if ((count != 0 && count != validator(line)))
		{
			make_it_free(*coords);
			exit((int)(write(1, "Map error, exit\n", 16)));
		}
		parser_line(line, coords, &k);
		free(line);
	}
	if (*(coords) == NULL)
	{
		perror("error");
		exit(1);
	}
	image->current_x = count;
	image->current_y = k;
	return (1);
}

int				validator(char *line)
{
	int			count;

	count = 0;
	while (*line)
	{
		if (*line && *line >= '0' && *line <= '9')
		{
			count++;
			while (*line >= '0' && *line <= '9')
				line++;
		}
		else if ((!(*line >= '0' && *line <= '9') && (*line != '-')
		&& (*line != ' ') && (*line != ',')))
			exit((int)(write(1, "Map error, exit\n", 16)));
		if (*line)
			line++;
	}
	return (count);
}

void			parser_line(char *line, t_coords **coords, int *k)
{
	static int	arr[3];
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) || line[i] == ',')
		{
			arr[1] = *k;
			arr[2] = ft_atoi(&line[i]);
			while (line[i] >= '0' && line[i] <= '9')
				i++;
			if (line[i] == ',')
				parser_f(arr, line, &i, *coords);
			else
				parser_list(arr, 0x0000ff, coords);
			arr[0]++;
		}
		if (line[i])
			i++;
	}
	arr[0] = 0;
	*k += 1;
}

void			parser_f(int *arr, char *line, int *i, t_coords *coords)
{
	*i += 3;
	parser_list(arr, ft_atoi_base(&line[*i], 16), &coords);
}
