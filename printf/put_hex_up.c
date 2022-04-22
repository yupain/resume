/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:47:51 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/28 20:08:00 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		intlen_hex(unsigned long int n)
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

static int		pow_st(int n)
{
	int	i;

	i = 1;
	while (n != 1)
	{
		i *= 16;
		n--;
	}
	return (i);
}

static	void	char_hex(unsigned long int n, int i)
{
	int kek;

	i = pow_st(i);
	if ((n / i) >= 0 && (n / i) <= 9)
	{
		kek = n / i + '0';
		write(1, &kek, 1);
	}
	else if (n / i == 10)
		write(1, "A", 1);
	else if (n / i == 11)
		write(1, "B", 1);
	else if (n / i == 12)
		write(1, "C", 1);
	else if (n / i == 13)
		write(1, "D", 1);
	else if (n / i == 14)
		write(1, "E", 1);
	else
		write(1, "F", 1);
}

int				put_hex_up(unsigned long long int n)
{
	int		i;

	i = intlen_hex(n);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i > 0)
	{
		char_hex(n, i);
		n %= pow_st(i);
		i--;
	}
	return (i);
}
