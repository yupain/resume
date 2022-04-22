/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:51:12 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/28 20:03:23 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			put_p_char(int c, t_strukt *map)
{
	int		i;

	i = 0;
	if (map->width < 0)
	{
		map->width *= -1;
		map->flags = -1;
	}
	if (map->flags == -1)
		write(1, &c, 1);
	if (map->width > 1)
		while (map->width > 1)
		{
			if (map->flags == 0)
				write(1, " ", 1);
			else if (map->flags == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			map->width--;
			map->length++;
		}
	if (map->flags != -1)
		write(1, &c, 1);
	map->length++;
}

void			put_p_perc(t_strukt *map)
{
	put_p_char('%', map);
}
