/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:44:56 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 16:45:24 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_stack *stack, int i)
{
	if (ps_st_ln(stack) != 1 && ps_st_ln(stack))
	{
		stack->intl->next = stack->ints;
		stack->intl = stack->intl->next;
		stack->ints = stack->ints->next;
		stack->intl->next = NULL;
	}
	if (i == 1)
		write(1, "ra\n", 3);
	if (i == 2)
		write(1, "rb\n", 3);
}

void	ps_rotate_all(t_push *push)
{
	ps_rotate(push->a, 0);
	ps_rotate(push->b, 0);
	write(1, "rr\n", 3);
}

void	ps_r_rotate(t_stack *stack, int i)
{
	t_intl	*buf;

	if (ps_st_ln(stack) == 1 || !ps_st_ln(stack))
		return ;
	buf = stack->ints;
	while (buf->next->next)
		buf = buf->next;
	buf->next = NULL;
	stack->intl->next = stack->ints;
	stack->ints = stack->intl;
	buf = stack->ints;
	while (buf->next)
		buf = buf->next;
	stack->intl = buf;
	if (i == 1)
		write(1, "rra\n", 4);
	if (i == 2)
		write(1, "rrb\n", 4);
}

void	ps_r_all_rotate(t_push *push)
{
	ps_r_rotate(push->a, 0);
	ps_r_rotate(push->b, 0);
	write(1, "rrr\n", 4);
}
