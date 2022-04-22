/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:26:00 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 16:49:29 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print(t_stack *stack)
{
	t_intl	*buf;

	if (!stack)
		return ;
	buf = stack->ints;
	if (stack->sp == 1)
		write(1, "a = ", 4);
	if (stack->sp == 2)
		write(1, "b = ", 4);
	while (buf)
	{
		printf("|%d|", buf->ind);
		buf = buf->next;
	}
	printf("\n");
}

int	ps_n_ln(t_intl *n)
{
	t_intl	*buf;
	int		i;

	i = 1;
	if (!n)
		return (0);
	buf = n;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	return (i);
}

int	ps_st_ln(t_stack *stack)
{
	int		i;
	t_intl	*buf;

	i = 1;
	if (!stack->ints)
		return (0);
	buf = stack->ints;
	while (buf->next)
	{
		buf = buf->next;
		i++;
	}
	return (i);
}

void	ps_swap(t_stack *stack, int i)
{
	t_intl	*buf;

	if (!ps_st_ln(stack))
	{
		if (stack->sp == 1 && i == 0)
			write(1, "sa\n", 3);
		else if (stack->sp == 2 && i == 0)
			write(1, "sb\n", 3);
		return ;
	}
	if (ps_st_ln(stack) != 1)
	{
		buf = stack->ints;
		stack->ints = stack->ints->next;
		buf->next = stack->ints->next;
		stack->ints->next = buf;
		if (ps_st_ln(stack) == 2)
			stack->intl = stack->ints->next;
	}
	if (stack->sp == 1 && i == 0)
		write(1, "sa\n", 3);
	else if (stack->sp == 2 && i == 0)
		write(1, "sb\n", 3);
}

void	ps_swapall(t_push *push)
{
	ps_swap(push->a, 1);
	ps_swap(push->b, 1);
	write(1, "ss\n", 3);
}
