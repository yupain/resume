/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:11:09 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/11/13 18:27:34 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;
	char	*fs;
	size_t	i;

	i = 0;
	c = (char *)s;
	if (!s)
		return (NULL);
	if (!(fs = (char *)malloc(sizeof(char) * (ft_strlen(c) + 1))))
		return (NULL);
	while (c[i])
	{
		fs[i] = f(i, c[i]);
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
