/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:42:07 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/28 20:42:55 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoph.h"

size_t	ph_time(t_couisine *table, int i)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (i == 1)
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	else
		return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - table->s_time);
}

void	upgrade_usleep(double msec)
{
	size_t	start;

	start = ph_time(NULL, 1);
	while (ph_time(NULL, 1) - start < msec)
		usleep(100);
}

long long	ph_atoi(char *str)
{
	int			i;
	int			k;
	long long	num;

	i = 0;
	num = 0;
	if (!str)
		return (2147483648);
	while (str[i])
	{
		k = str[i++] - '0';
		num = k + (num * 10);
		if (num > 2147483647)
			return (2147483648);
	}
	return (num);
}

int	ph_check_argv(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	ph_parser(int argc, char **argv, t_couisine *table)
{
	table->nu_ph = ph_atoi(argv[1]);
	table->ttd = ph_atoi(argv[2]);
	table->tte = ph_atoi(argv[3]);
	table->tts = ph_atoi(argv[4]);
	if (argc == 6)
		table->nu_te = ph_atoi(argv[5]);
	else
		table->nu_te = -1;
	if (table->nu_te == -2147483648 || table->tts == -2147483648
		|| table->tte == -2147483648 || table->ttd == -2147483648
		|| table->nu_ph == -2147483648)
		return (0);
	return (1);
}
