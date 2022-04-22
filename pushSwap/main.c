/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:32:14 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 20:38:57 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_push *push)
{
	t_intl	*buf;

	buf = push->a->ints;
	get_ind(push);
	if (ps_st_ln(push->a) >= 3)
		ps_b_fill(push);
	else if (ps_st_ln(push->a) == 2 && push->a->ints->ind != 0)
		ps_swap(push->a, 0);
	if (ps_st_ln(push->b))
		ps_a_fill(push);
	ps_a_to_up(push->a);
}

void	ps_free(t_push *push)
{
	t_intl	*buf;
	t_intl	*fbuf;

	if (push->a->ints)
	{
		buf = push->a->ints;
		while (buf)
		{
			fbuf = buf;
			buf = buf->next;
			free(fbuf);
		}
	}
	if (push->b->ints)
	{
		buf = push->b->ints;
		while (buf)
		{
			fbuf = buf;
			buf = buf->next;
			free(fbuf);
		}
	}
	free(push->a);
	free(push->b);
}

int	ps_if_sorted(t_stack *stack)
{
	t_intl	*buf;

	buf = stack->ints;
	while (buf->next)
	{
		if ((buf->ind + 1) != (buf->next->ind))
			return (1);
		buf = buf->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_push	push;
	t_intl	k;

	if (argc == 2)
		return (0);
	if (argc < 2 || !(num_check(argv)) || !(init_struct(&push)))
		return (ret_err());
	i = 1;
	while (argv[i])
	{
		k.i = ps_atoi(argv[i]);
		if (k.i == 2147483648)
			return (ret_err());
		put_last_a(&k, &push);
		i++;
	}
	if (!put_ind(&push))
		return (0);
	sorter(&push);
	ps_free(&push);
	return (0);
}
