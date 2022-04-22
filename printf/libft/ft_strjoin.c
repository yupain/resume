/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:00:57 by jwhirlpo          #+#    #+#             */
/*   Updated: 2021/01/23 16:10:39 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	char	*ss;

	i = 0;
	x = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(ss = (char *)malloc((ft_strlen(s1) + ft_strlen(s2))
					* sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
		ss[i++] = s1[x++];
	x = 0;
	while (s2[x])
		ss[i++] = s2[x++];
	ss[i] = '\0';
	return (ss);
}
