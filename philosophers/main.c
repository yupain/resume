/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:41:52 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/28 20:48:11 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoph.h"

void	*ph_if_ded(void *tabl)
{
	t_couisine	*table;
	t_phl		*buf;

	table = (t_couisine *)tabl;
	table->i = 0;
	upgrade_usleep(0.005);
	while (table->if_ded == -1 && table->if_ded != -2)
	{
		table->i = 0;
		buf = table->phs;
		while (buf)
		{
			if ((ph_time(table, 1) - buf->le) > (unsigned int)table->ttd)
			{
				table->ded_t = ph_time(table, 2);
				table->if_ded = buf->ind;
			}
			if (table->nu_te < buf->et && table->nu_te != -1)
				table->i = -1;
			buf = buf->next;
		}
	}
	return (0);
}

int	ph_borda(t_couisine *table)
{
	t_phl	*buf;

	buf = table->phs;
	table->post = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->post, NULL);
	while (buf)
	{
		if (pthread_create(&buf->patok, NULL, ph_pasta, buf))
			return (0);
		buf = buf->next;
	}
	pthread_create(&table->smert, NULL, ph_if_ded, table);
	return (1);
}

int	ph_init(t_couisine *table)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (i++ < table->nu_ph)
	{
		if (!(ph_creat(table, k)))
			return (0);
		k++;
	}
	if (!(ph_fork_init(table)))
		return (0);
	if (!(ph_borda(table)))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_couisine	table;

	if (argc != 5 && argc != 6)
		return (ph_err_ret("Error:\nNumber of arguments.\n", NULL));
	if (!(ph_check_argv(argv)))
		return (ph_err_ret("Error:\nWrong arguments.\n", NULL));
	table.s_time = ph_time(&table, 1);
	if (!(ph_parser(argc, argv, &table)))
		return (ph_err_ret("Error:\nParser error.\n", NULL));
	if (!(ph_init(&table)))
		return (ph_err_ret("Error:\nInit error.\n", &table));
	while (1)
	{
		if (table.if_ded != -1)
			break ;
	}
	if (table.if_ded != -2)
		printf("%zu %d is dead\n", ph_time(&table, 2), table.if_ded);
	return (0);
}
