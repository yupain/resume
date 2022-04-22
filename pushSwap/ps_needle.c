/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_needle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <jwhirlpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 21:11:44 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/07/26 21:28:24 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_i(t_push *push, t_intl *buf)
{
	int	i;

	if (!buf)
		i = ps_find(push, push->b->ints);
	else
		i = ps_find(push, buf);
	if (i > (ps_st_ln(push->a) / 2))
		i = ps_st_ln(push->a) - i;
	return (i);
}

int	ps_i_a(t_push *push, int i, int i_a, int k)
{
	if ((i > (i_a + k) && k < (ps_st_ln(push->a) / 2)))
	{
		i = i_a + k;
	}
	else if ((i > (i_a + (ps_st_ln(push->b)) - k)
			&& k >= (ps_st_ln(push->a) / 2)))
	{
		i = i_a + (ps_st_ln(push->b)) - k;
	}
	return (i);
}
