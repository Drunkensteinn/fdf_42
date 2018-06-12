/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:44:58 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/22 21:44:59 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero_int(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (size > i)
	{
		tab[i] = 0;
		i++;
	}
}