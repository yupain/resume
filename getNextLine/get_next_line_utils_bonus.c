/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:34:20 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/12/23 18:16:12 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			substr[j] = s[i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *c)
{
	size_t i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	x;
	char	*ss;

	i = 0;
	x = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(ss = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
					* sizeof(char))))
		return (NULL);
	if (s1)
		while (s1[i] != '\0')
			ss[i++] = s1[x++];
	x = 0;
	while (s2[x])
		ss[i++] = s2[x++];
	ss[i] = '\0';
	free(s1);
	return (ss);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		last;
	char	*x;

	i = 0;
	x = (char *)s;
	last = ft_strlen(x);
	if (!s)
		return (NULL);
	if (c == '\0')
		return (&x[last]);
	while (x[i] != '\0')
	{
		if (x[i] == (char)c)
			return (&x[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	char	*c;
	size_t	lensrc;
	size_t	i;

	i = 0;
	lensrc = ft_strlen(src);
	if (!(c = (char *)malloc(sizeof(char) * (lensrc + 1))))
		return (NULL);
	while (src[i] != '\0')
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
