/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:02:40 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/16 18:09:39 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *small, size_t len)
{
	size_t	pos;
	size_t	i;
	char	*str1;
	char	*small1;

	pos = 0;
	str1 = (char *)str;
	small1 = (char *)small;
	if (!*small)
		return (str1);
	while (str1[pos] != '\0' && pos < len)
	{
		if (str1[pos] == *small1)
		{
			i = 1;
			while (small1[i] != '\0' && str1[pos + i] == small1[i] &&
					(pos + i) < len)
				i++;
			if (small1[i] == '\0')
				return (&str1[pos]);
		}
		pos++;
	}
	return (NULL);
}
