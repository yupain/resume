/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:19:50 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/29 02:48:11 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# include <stdio.h>

typedef struct		s_strukt
{
	int			i;
	int			j;
	int			flags;
	int			presicion;
	int			spec_pres;
	int			width;
	int			spec_wid;
	int			length;
	char		type;
	char		*types;
	va_list		ap;
}					t_strukt;

int					ft_printf(const char *line, ...);

void				wht_spec(t_strukt *map);

int					put_p_hex_low(unsigned int n, t_strukt *map);
int					put_hex_low(unsigned long long int n);
int					put_p_hex_up(unsigned int n, t_strukt *map);
int					put_hex_up(unsigned long long int n);

void				put_p_int(long int n, t_strukt *map);
void				put_p_char(int c, t_strukt *map);
void				put_p_perc(t_strukt *map);
void				put_p_pointer(unsigned long int n, t_strukt *map);
void				put_p_str(char *str, t_strukt *map);

int					intlen(long int n);
long int			pow_ten(long int n);
void				int_iter(t_strukt *map, int i);
void				pars_resources(t_strukt *map);

#endif
