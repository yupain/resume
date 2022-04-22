/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:22:13 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/29 02:55:57 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static size_t	width(t_strukt *map, char *line, size_t i)
{
	if (ft_isdigit(line[i]) && line[i] != '0')
		while (ft_isdigit(line[i]) && line[i])
		{
			map->width = map->width * 10 + line[i] - '0';
			map->spec_wid = 1;
			i++;
		}
	else if (line[i] == '*')
	{
		map->width = va_arg(map->ap, unsigned int);
		map->spec_wid = 1;
		i++;
	}
	return (i);
}

static size_t	presicion(t_strukt *map, char *line, size_t i)
{
	if (line[i] == '.' && ft_isdigit(line[i + 1]))
	{
		map->spec_pres = 1;
		i++;
		while (ft_isdigit((line[i])) && line[i])
		{
			map->presicion = map->presicion * 10 + line[i] - '0';
			i++;
		}
	}
	else if (line[i] == '.' && line[i + 1] == '*')
	{
		map->presicion = va_arg(map->ap, int);
		map->spec_pres = 1;
		i++;
	}
	else if (line[i] == '.' && !(line[i + 1] == '*' || ft_isdigit(line[i + 1])))
	{
		map->presicion = 0;
		map->spec_pres = 1;
		i++;
	}
	return (i);
}

static size_t	pars_flags(t_strukt *map, char *line, size_t i)
{
	if (line[i] == '-')
	{
		map->flags = -1;
		i++;
	}
	if (line[i] == '0' && line[i + 1] != '-')
	{
		if (map->flags != -1)
			map->flags = 1;
		i++;
	}
	return (i);
}

static char		*pars_line(char *line, t_strukt *map)
{
	size_t i;

	i = 1;
	pars_resources(map);
	while (line[i])
	{
		if (line[i] == '-' || line[i] == '0')
			i = pars_flags(map, line, i);
		if ((ft_isdigit(line[i]) && line[i] != '0') || line[i] == '*')
			i = width(map, line, i);
		if (line[i] == '.')
			i = presicion(map, line, i);
		if (ft_strchr(map->types, line[i]))
		{
			map->type = line[i];
			i++;
			wht_spec(map);
			return (&line[i]);
		}
		i++;
	}
	return (&line[i]);
}

int				ft_printf(const char *line, ...)
{
	t_strukt	map;
	char		*c;

	map.length = 0;
	c = (char *)line;
	va_start(map.ap, line);
	while (*c != '\0')
	{
		if (*c == '%')
		{
			if (!(c = pars_line(c, &map)))
			{
				va_end(map.ap);
				return (0);
			}
		}
		else
		{
			write(1, c, 1);
			c++;
			map.length += 1;
		}
	}
	va_end(map.ap);
	return (map.length);
}
