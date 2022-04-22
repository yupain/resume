/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex_low.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:47:37 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/28 20:10:48 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	unsigned long long int	intlen_hex(unsigned long long int n)
{
	unsigned long long int	i;

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

static unsigned long long int	pow_st(int n)
{
	unsigned long long int	i;

	i = 1;
	while (n != 1)
	{
		i *= 16;
		n--;
	}
	return (i);
}

static	void					char_hex(unsigned long long int n,
											unsigned long long int i)
{
	unsigned long long int kek;

	i = pow_st(i);
	if ((n / i) >= 0 && (n / i) <= 9)
	{
		kek = n / i + '0';
		write(1, &kek, 1);
	}
	else if (n / i == 10)
		write(1, "a", 1);
	else if (n / i == 11)
		write(1, "b", 1);
	else if (n / i == 12)
		write(1, "c", 1);
	else if (n / i == 13)
		write(1, "d", 1);
	else if (n / i == 14)
		write(1, "e", 1);
	else
		write(1, "f", 1);
}

int								put_hex_low(unsigned long long int n)
{
	unsigned long long int	i;

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
