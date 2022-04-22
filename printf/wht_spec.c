/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wht_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:06:38 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/28 20:03:48 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			wht_spec(t_strukt *map)
{
	if (map->type == 'c')
		put_p_char((va_arg(map->ap, int)), map);
	else if (map->type == 's')
		put_p_str(va_arg(map->ap, char *), map);
	else if (map->type == 'p')
		put_p_pointer(va_arg(map->ap, unsigned long int), map);
	else if (map->type == 'i' || map->type == 'd')
		put_p_int(va_arg(map->ap, int), map);
	else if (map->type == 'u')
		put_p_int(va_arg(map->ap, unsigned int), map);
	else if (map->type == 'x')
		put_p_hex_low(va_arg(map->ap, unsigned int), map);
	else if (map->type == 'X')
		put_p_hex_up(va_arg(map->ap, unsigned int), map);
	else if (map->type == '%')
		put_p_perc(map);
}
