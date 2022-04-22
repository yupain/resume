/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:57:32 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/29 02:58:39 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				intlen(long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

long	int		pow_ten(long int n)
{
	int	i;

	i = 1;
	while (n != 1)
	{
		i *= 10;
		n--;
	}
	return (i);
}

void			int_iter(t_strukt *map, int i)
{
	if (i == 1)
	{
		write(1, "0", 1);
		map->width--;
		map->length++;
	}
}

void			pars_resources(t_strukt *map)
{
	map->flags = 0;
	map->presicion = 0;
	map->spec_pres = 0;
	map->width = 0;
	map->spec_wid = 0;
	map->type = 0;
	map->types = "cspdiuxX%";
}
