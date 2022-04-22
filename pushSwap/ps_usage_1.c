/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_usage_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:08:14 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 17:12:59 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_struct(t_push *push)
{
	push->a = malloc(sizeof(t_stack));
	push->b = malloc(sizeof(t_stack));
	if (!push->a || !push->b)
		return (0);
	push->a->ints = NULL;
	push->a->intl = NULL;
	push->a->sp = 1;
	push->b->ints = NULL;
	push->b->intl = NULL;
	push->b->sp = 2;
	push->sort_fl = 0;
	return (1);
}

int	ps_get_med(t_stack *stack)
{
	t_intl	*buf;
	int		i;

	i = 0;
	buf = stack->ints;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	return (i / 2);
}

void	get_ind(t_push *push)
{
	t_intl	*buf;
	int		i;

	i = 0;
	buf = push->a->ints;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	push->max_ind = i;
	push->med_ind = ps_get_med(push->a);
}

void	ps_sort_a_3(t_push *push)
{
	if (push->a->ints->ind == 0)
	{
		if (push->a->ints->next->ind == push->med_ind)
			ps_r_rotate(push->a, 1);
		else
			ps_swap(push->a, 0);
	}
	else if (push->a->ints->next->ind == 0)
	{
		if (push->a->ints->ind == push->med_ind)
		{
			ps_swap(push->a, 0);
			ps_r_rotate(push->a, 1);
		}
	}
	else if (push->a->intl->ind == 0)
	{
		if (push->a->ints->next->ind == push->med_ind)
			ps_swap(push->a, 0);
		ps_rotate(push->a, 1);
	}
}

void	ps_b_fill(t_push *push)
{
	while (ps_st_ln(push->a) != 3)
	{
		if (push->a->ints->ind == 0 || push->a->ints->ind == push->max_ind
			|| push->a->ints->ind == push->med_ind)
			ps_rotate(push->a, 1);
		else
		{
			ps_push_b(push);
			if (push->med_ind > push->b->ints->ind)
				ps_rotate(push->b, 2);
		}
	}
	ps_sort_a_3(push);
}
