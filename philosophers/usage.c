/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 20:47:24 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/28 20:48:20 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoph.h"

int	ph_err_ret(char *str, t_couisine *table)
{
	(void)table;
	printf("%s", str);
	return (1);
}

int	ph_creat(t_couisine *table, int k)
{
	t_phl	*buf;

	if (!table->phs)
	{
		table->phs = malloc(sizeof(t_phl));
		table->phs->ind = k;
		table->phs->next = NULL;
		table->phs->table = table;
		table->if_ded = -1;
	}
	else
	{
		buf = table->phs;
		while (buf->next)
			buf = buf->next;
		buf->next = malloc(sizeof(t_phl));
		buf->next->ind = k;
		buf->next->table = table;
		buf->next->next = NULL;
	}
	return (1);
}

int	ph_fork_init(t_couisine *table)
{
	int		i;
	t_phl	*buf;

	i = 0;
	buf = table->phs;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nu_ph);
	if (!table->forks)
		return (0);
	while (i < table->nu_ph)
		if (pthread_mutex_init(&table->forks[i++], NULL))
			return (0);
	while (buf->next)
	{
		buf->left = &table->forks[buf->ind - 1];
		buf->right = &table->forks[buf->ind];
		buf = buf->next;
	}
	buf->left = &table->forks[buf->ind - 1];
	buf->right = &table->forks[0];
	return (1);
}

void	ph_post(char *str, t_phl *philo)
{
	pthread_mutex_lock(philo->table->post);
	if (philo->table->if_ded == -1)
		printf("%zu %d %s\n", ph_time(philo->table, 2), philo->ind, str);
	pthread_mutex_unlock(philo->table->post);
}

void	*ph_pasta(void *phil)
{
	t_phl	*philo;

	philo = (t_phl *)phil;
	philo->le = ph_time(philo->table, 1);
	if (philo->ind % 2 == 0)
		upgrade_usleep(0.005);
	philo->et = 0;
	while (philo->table->if_ded != -2)
	{
		pthread_mutex_lock(philo->left);
		ph_post("has taken a fork", philo);
		pthread_mutex_lock(philo->right);
		philo->le = ph_time(philo->table, 1);
		ph_post("has taken a fork", philo);
		ph_post("is eating", philo);
		philo->et++;
		upgrade_usleep(philo->table->tte);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		ph_post("is sleeping", philo);
		upgrade_usleep(philo->table->tts);
		ph_post("is thinking", philo);
	}
	return (0);
}
