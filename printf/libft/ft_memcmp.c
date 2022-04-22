/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:47:59 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/04 21:14:28 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			c;
	unsigned char	*ss1;
	unsigned char	*ss2;

	c = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (c < n)
	{
		if (ss1[c] != ss2[c])
			return (ss1[c] - ss2[c]);
		c++;
	}
	return (0);
}
