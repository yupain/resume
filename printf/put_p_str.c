/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:59:10 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/28 18:29:17 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		resources(t_strukt *map, char *str)
{
	map->j = ft_strlen(str);
	map->i = 0;
	if (!str)
		map->j = 6;
	if (map->presicion < 0)
		map->spec_pres = 0;
	if (map->width < 0)
	{
		map->width *= -1;
		map->flags = -1;
	}
	if (map->spec_pres == 1 && map->flags == 1)
		map->flags = 0;
	if (map->spec_pres == 1 && map->presicion < map->j)
		map->j = map->presicion;
	if (map->width < map->j)
		map->width = 0;
}

static void		put_prev(t_strukt *map)
{
	if (map->flags == 0)
		while (map->width > map->j && map->width != map->j)
		{
			write(1, " ", 1);
			map->length++;
			map->width--;
		}
	if (map->flags == 1)
		while (map->width > map->j && map->width != map->j)
		{
			write(1, "0", 1);
			map->length++;
			map->width--;
		}
}

void			put_p_str(char *str, t_strukt *map)
{
	resources(map, str);
	if (map->flags == 0 || map->flags == 1)
		put_prev(map);
	if (str)
		while (map->i < map->j && str[map->i] != '\0')
			write(1, &str[map->i++], 1);
	else
	{
		write(1, "(null)", map->j);
		map->length += map->j;
	}
	if (map->flags == -1)
		while (map->width > map->j && map->width != map->j)
		{
			write(1, " ", 1);
			map->length++;
			map->width--;
		}
	map->length += map->i;
}
