/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:01:06 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/29 00:15:28 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		resources(t_strukt *map, long int n)
{
	map->j = intlen(n);
	map->i = intlen(n);
	if (map->presicion < 0)
		map->spec_pres = 0;
	if (map->width < 0)
	{
		map->width *= -1;
		map->flags = -1;
	}
	if (map->spec_pres == 1 && map->flags == 1)
		map->flags = 0;
	if (map->width < map->j)
		map->width = 0;
	if (map->presicion > map->j && n >= 0)
		map->j = map->presicion;
	else if (map->presicion >= map->j && n < 0)
		map->j = map->presicion + 1;
	if (map->spec_pres == 1 && map->presicion == 0 && n == 0)
	{
		map->j = 0;
		map->i = 0;
	}
}

static long int	put_neg(t_strukt *map, long int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		map->length++;
		map->i--;
	}
	return (n);
}

static void		put_prev(t_strukt *map, long int n)
{
	if (map->flags == 0)
	{
		if (map->width > map->j)
			while (map->width > map->j && map->width > 0)
			{
				write(1, " ", 1);
				map->width--;
				map->length++;
			}
		n = put_neg(map, n);
		if (map->presicion > map->i)
			while (map->presicion > map->i && map->presicion > 0)
			{
				write(1, "0", 1);
				map->presicion--;
				map->length++;
			}
	}
}

static void		put_last(t_strukt *map, long int n)
{
	int	k;

	if (!(n == 0 && map->presicion == 0 && map->spec_pres == 1))
		while (map->i > 0)
		{
			k = n / pow_ten(map->i) + '0';
			write(1, &k, 1);
			n %= pow_ten(map->i);
			map->i--;
			map->length++;
			map->presicion--;
		}
	if (map->flags == -1)
		if (map->width > map->j)
			while (map->width > map->j && map->width > 0)
			{
				write(1, " ", 1);
				map->width--;
				map->length++;
			}
}

void			put_p_int(long int n, t_strukt *map)
{
	map->i = intlen(n);
	resources(map, n);
	if (map->flags == 0)
		put_prev(map, n);
	if (map->flags == 1)
	{
		n = put_neg(map, n);
		while (map->width > map->j && map->width > 0)
			int_iter(map, 1);
	}
	if (map->flags == -1)
	{
		n = put_neg(map, n);
		if (map->presicion > map->i)
			while (map->presicion > map->i && map->presicion > 0)
			{
				write(1, "0", 1);
				map->presicion--;
				map->length++;
			}
	}
	if (n < 0)
		n *= -1;
	put_last(map, n);
}
