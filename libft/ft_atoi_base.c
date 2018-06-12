/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 21:57:14 by ablizniu          #+#    #+#             */
/*   Updated: 2018/06/09 21:57:16 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			lower_case(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			str[i] = (char)(str[i] + 32);
		i++;
	}
}

int				base(char str)
{
	if (str >= '0' && str <= '9')
		return (str - 48);
	if (str >= 'a' && str <= 'f')
		return (str - 97 + 10);
	return (0);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int			i;
	long int	res;
	int			sign;
	char		*buff;

	if (str == NULL)
		return (0);
	if (str_base == 0)
		return (0);
	buff = (char *)str;
	i = 0;
	sign = 0;
	res = 0;
	lower_case(buff);
	if (buff[i] == '+')
		i++;
	else if (buff[i] == '-')
	{
		sign = 1;
		i++;
	}
	while ((buff[i] >= '0' && buff[i] <= '9') ||
	(buff[i] >= 'a' && buff[i] <= 'f'))
		res = res * (long int)str_base + (base(buff[i++]));
	return (int)(sign ? -res : res);
}
