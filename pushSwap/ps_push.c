/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:48:12 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 16:48:35 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_a(t_push *push)
{
	t_intl	*buf;

	if (ps_st_ln(push->b))
	{
		buf = push->b->ints;
		push->b->ints = push->b->ints->next;
		buf->next = push->a->ints;
		push->a->ints = buf;
	}
	if (ps_st_ln(push->a) == 2)
		push->a->intl = push->a->ints->next;
	if ((ps_st_ln(push->b) == 1))
		push->b->intl = NULL;
	write(1, "pa\n", 3);
}

void	ps_push_b(t_push *push)
{
	t_intl	*buf;

	if (ps_st_ln(push->a))
	{
		buf = push->a->ints;
		push->a->ints = push->a->ints->next;
		buf->next = push->b->ints;
		push->b->ints = buf;
	}
	if (ps_st_ln(push->b) == 2)
		push->b->intl = push->b->ints->next;
	if ((ps_st_ln(push->a) == 1))
		push->a->intl = NULL;
	write(1, "pb\n", 3);
}
