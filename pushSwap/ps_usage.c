/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:03:43 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 21:10:53 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ret_err(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (0);
}

int	num_check(char **argv)
{
	int	i;
	int	k;

	k = 1;
	while (argv[k])
	{
		i = 0;
		while (ft_isdigit(argv[k][i]) || argv[k][i] == '-' || argv[k][i] == '+')
			i++;
		if (argv[k][i] != '\0' && !(ft_isdigit(argv[k][i])))
			return (0);
		k++;
	}
	return (1);
}

void	put_last_a(t_intl *k, t_push *push)
{
	if (!(push->a->ints))
	{
		push->a->ints = malloc(sizeof(t_intl));
		push->a->ints->i = k->i;
		push->a->ints->next = NULL;
		push->a->intl = push->a->ints;
	}
	else
	{
		push->a->intl->next = malloc(sizeof(t_intl));
		push->a->intl->next->i = k->i;
		push->a->intl->next->next = NULL;
		push->a->intl = push->a->intl->next;
	}
}

long long	ps_atoi(char *str)
{
	int			i;
	int			pt;
	int			k;
	long long	num;

	i = 0;
	pt = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pt = -1;
		i++;
	}
	while (str[i])
	{
		k = str[i++] - '0';
		num = k + (num * 10);
		if (num > 2147483647)
			return (2147483648);
	}
	return (num * pt);
}

int	put_ind(t_push *push)
{
	t_intl	*buf1;
	t_intl	*buf2;
	int		ind;

	buf1 = push->a->ints;
	while (buf1 != NULL)
	{
		ind = 0;
		buf2 = push->a->ints;
		while (buf2)
		{
			if ((int)buf1->i > (int)buf2->i)
				ind++;
			if ((int)buf1->i == (int)buf2->i && buf1 != buf2)
			{
				write(1, "Error\n", 6);
				ps_free(push);
				return (0);
			}
			buf2 = buf2->next;
		}
		buf1->ind = ind;
		buf1 = buf1->next;
	}
	return (1);
}
