/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:00:25 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/28 19:18:38 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			intlen_h(unsigned long int n)
{
	int	i;

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

static void			iter(t_strukt *map, int i)
{
	if (i == 1)
	{
		write(1, " ", 1);
		map->width--;
		map->length++;
	}
	if (i == 0)
	{
		write(1, "0", 1);
		map->presicion--;
		map->length++;
	}
}

static void			resources(t_strukt *map, unsigned long int n)
{
	map->j = intlen_h(n);
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
		map->j = map->presicion;
	if (map->spec_pres == 1 && map->presicion == 0 && n == 0)
	{
		map->j = 0;
		map->i = 0;
	}
}

static void			put_prev(t_strukt *map)
{
	if (map->flags == 0)
	{
		if (map->width > (map->j + 2))
			while (map->width > (map->j + 2) && map->width > 0)
				iter(map, 1);
		write(1, "0x", 2);
		map->length += 2;
		if (map->presicion > map->i)
			while (map->presicion > map->i)
				iter(map, 0);
	}
	if (map->flags == 1)
	{
		write(1, "0x", 2);
		map->length += 2;
		while (map->width > (map->j + 2) && map->width > 0)
		{
			write(1, "0", 1);
			map->width--;
			map->length++;
		}
	}
}

void				put_p_pointer(unsigned long int n, t_strukt *map)
{
	resources(map, n);
	if (map->flags == 0 || map->flags == 1)
		put_prev(map);
	if (map->flags == -1)
	{
		write(1, "0x", 2);
		map->length += 2;
		if (map->presicion > map->i)
			while (map->presicion > map->i && map->presicion > 0)
				iter(map, 0);
	}
	if (!(n == 0 && map->presicion == 0 && map->spec_pres == 1))
	{
		put_hex_low(n);
		map->length += intlen_h(n);
	}
	if (map->flags == -1)
		if (map->width > map->j)
			while (map->width > (map->j + 2) && map->width > 0)
				iter(map, 1);
}
