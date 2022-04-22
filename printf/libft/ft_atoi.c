/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:40:42 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/06 16:17:52 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int	i;
	int	pn;
	int	b;

	i = 0;
	b = 0;
	pn = 1;
	while ((nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
				nptr[i] == '\v' || nptr[i] == '\f' ||
				nptr[i] == '\r') && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			pn = (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		b = b * 10 + nptr[i] - '0';
		i++;
	}
	return (b * pn);
}
