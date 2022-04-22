/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_usage_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:09:30 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 21:27:46 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_find(t_push *push, t_intl *b_int)
{
	int		i;
	t_intl	*buf;

	i = 1;
	buf = push->a->ints;
	if (push->a->ints->ind > b_int->ind && push->a->intl->ind < b_int->ind
		&& push->a->intl->ind != push->max_ind && push->a->ints->ind != 0)
		return (0);
	while (buf->next)
	{
		if (buf->ind > b_int->ind && buf->next->ind < b_int->ind
			&& buf->next->ind != 0 && buf->ind != push->max_ind)
			return (i);
		else if (buf->ind < b_int->ind && buf->next->ind > b_int->ind
			&& buf->next->ind != 0 && buf->ind != push->max_ind)
			return (i);
		i++;
		buf = buf->next;
	}
	return (i);
}

int	ps_b_rot(t_push *push)
{
	int		k;
	int		j;
	int		i;
	int		i_a;
	t_intl	*buf;

	if (!(ps_i(push, NULL)))
		return (0);
	i = ps_i(push, NULL);
	k = 0;
	j = 0;
	buf = push->b->ints;
	while (buf)
	{
		i_a = ps_i(push, buf);
		if (i > (i_a + k) || i > (i_a + (ps_st_ln(push->b)) - k))
		{
			i = ps_i_a(push, i, i_a, k);
			j = k;
		}
		k++;
		buf = buf->next;
	}
	return (j);
}

int	ps_b_find(t_push *push)
{
	int		j;

	j = ps_b_rot(push);
	if (j > (ps_st_ln(push->b) / 2))
		j = j - ps_st_ln(push->b);
	if (j > 0)
		while (j-- > 0)
			ps_rotate(push->b, 2);
	else if (j < 0)
		while (j++ < 0)
			ps_r_rotate(push->b, 2);
	return (ps_find(push, push->b->ints));
}

void	ps_a_fill(t_push *push)
{
	int	i;

	while (ps_st_ln(push->b))
	{
		i = ps_b_find(push);
		if (i > (ps_st_ln(push->a) / 2))
			i = i - ps_st_ln(push->a);
		if (i == 0)
			ps_push_a(push);
		else if (i > 0)
		{
			while (i-- > 0)
				ps_rotate(push->a, 1);
			ps_push_a(push);
		}
		else if (i < 0)
		{
			while (i++ < 0)
				ps_r_rotate(push->a, 1);
			ps_push_a(push);
		}
	}
}

void	ps_a_to_up(t_stack *stack)
{
	t_intl	*buf;
	int		i;

	buf = stack->ints;
	i = 0;
	while (buf->ind != 0)
	{
		buf = buf->next;
		i++;
	}
	if (i > (ps_st_ln(stack) / 2))
		i = i - ps_st_ln(stack);
	if (i > 0)
		while (i-- > 0)
			ps_rotate(stack, 1);
	else if (i < 0)
		while (i++ < 0)
			ps_r_rotate(stack, 1);
}
