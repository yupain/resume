/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_hex_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:58:17 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/28 19:51:40 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			intlen_h(unsigned long int n)
{
	int			i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void			resources(t_strukt *map, unsigned int n)
{
	map->i = intlen_h(n);
	if (map->presicion < 0)
		map->spec_pres = 0;
	if (map->width < 0)
	{
		map->width *= -1;
		map->flags = -1;
	}
	if (map->spec_pres == 1 && map->flags == 1)
		map->flags = 0;
	if (map->width < map->i)
		map->width = 0;
	if (map->presicion > map->i)
		map->i = map->presicion;
	if (map->spec_pres == 1 && map->presicion == 0 && n == 0)
		map->i = 0;
}

static void			put_hex_f0(t_strukt *map, unsigned int n)
{
	if (map->flags == 0)
	{
		if (map->width > map->i)
			while (map->width > map->i && map->width > 0)
			{
				write(1, " ", 1);
				map->width--;
				map->length++;
			}
		if (map->presicion > intlen_h(n))
			while (map->presicion > intlen_h(n) && map->presicion > 0)
			{
				write(1, "0", 1);
				map->presicion--;
				map->length++;
			}
	}
}

static void			iter(t_strukt *map, int i)
{
	if (i == 1)
	{
		write(1, "0", 1);
		map->width--;
		map->length++;
	}
	if (i == 0)
	{
		write(1, "0", 1);
		map->presicion--;
		map->length++;
	}
	if (i == -1)
	{
		write(1, " ", 1);
		map->width--;
		map->length++;
	}
}

int					put_p_hex_up(unsigned int n, t_strukt *map)
{
	resources(map, n);
	if (map->flags == 0)
		put_hex_f0(map, n);
	if (map->flags == 1)
		if (map->width > map->i)
			while (map->width > map->i && map->width > 0)
				iter(map, 1);
	if (map->flags == -1)
		if (map->presicion > intlen_h(n))
			while (map->presicion > intlen_h(n) && map->presicion > 0)
				iter(map, 0);
	if (!(n == 0 && map->presicion == 0 && map->spec_pres == 1))
	{
		put_hex_up(n);
		map->length += intlen_h(n);
	}
	if (map->flags == -1)
		if (map->width > map->i)
			while (map->width > map->i && map->width > 0)
				iter(map, -1);
	return (0);
}
