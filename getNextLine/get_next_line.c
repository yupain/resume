/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhirlpo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:09:29 by jwhirlpo          #+#    #+#             */
/*   Updated: 2020/12/27 12:03:44 by jwhirlpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char *a, char *c, int i)
{
	if (a)
	{
		free(a);
		a = NULL;
	}
	if (c)
	{
		free(c);
		c = NULL;
	}
	if (i == -1)
		return (-1);
	else if (i == 0)
		return (0);
	else
		return (1);
}

static char	*ft_free_read(char **buf, char **sg)
{
	free(*buf);
	free(*sg);
	*buf = NULL;
	*sg = NULL;
	return (NULL);
}

static char	*ft_read(char *sg, int fd)
{
	char	*buf;
	int		rfd;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	while ((rfd = read(fd, buf, BUFFER_SIZE)) > 0 || !ft_strchr(sg, '\n'))
	{
		if (rfd < 0)
			return (ft_free_read(&buf, &sg));
		buf[rfd] = '\0';
		if (!(sg = ft_strjoin(sg, buf)))
			return (ft_free_read(&buf, &sg));
		if (ft_strchr(sg, '\n') || rfd < BUFFER_SIZE)
			break ;
	}
	free(buf);
	return (sg);
}

static char	*ft_rem(char *sg, char *remain)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = (char *)malloc(ft_strlen(sg) + 1)))
		return (NULL);
	while (sg[i] != '\0')
	{
		tmp[i] = sg[i];
		i++;
	}
	tmp[i] = '\0';
	free(remain);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	static char *remain[1024];
	char		*sg;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(remain[fd] = ft_read(remain[fd], fd)))
		return (-1);
	if (ft_strchr(remain[fd], '\n'))
	{
		sg = ft_strdup(remain[fd]);
		if (ft_strchr(remain[fd], '\n') + 1 != '\0')
			if (!(remain[fd] = ft_rem((ft_strchr(remain[fd], '\n') + 1),
							remain[fd])))
				return (ft_free(remain[fd], sg, -1));
		if (!(*line = ft_substr(sg, 0, (ft_strchr(sg, '\n') - sg))))
			return (ft_free(sg, remain[fd], -1));
		return (ft_free(sg, NULL, 1));
	}
	else
	{
		*line = ft_strdup(remain[fd]);
		free(remain[fd]);
		remain[fd] = NULL;
		return (0);
	}
}
