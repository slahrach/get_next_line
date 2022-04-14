/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:02:51 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/04 21:42:17 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifdef BUFFER_SIZE

static char	*ft_strndup(char *s1, int l)
{
	char		*ptr;

	ptr = (char *) malloc ((l + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy (ptr, s1, l + 1);
	return (ptr);
}

static char	*ft_strchr(char *s, int c)
{
	size_t	l;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	while (i <= l)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

static	char	*funct(char **store, char *buf, int fd, int *pr)
{
	int		i;
	char	*left;
	char	*line;

	while ((*pr) > 0 || ft_strchr(*store, '\n'))
	{
		buf[(*pr)] = '\0';
		*store = ft_strjoin(*store, buf);
		left = ft_strnchr(*store, '\n', &i);
		if (i != -1)
		{
			line = ft_strndup(*store, i);
			free(*store);
			if (left)
				*store = left;
			else
				*store = NULL;
			return (line);
		}
		*pr = read(fd, buf, BUFFER_SIZE);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*retur;
	static char	*store;
	char		*buf;
	int			r;
	char		*ret;

	buf = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	r = read(fd, buf, BUFFER_SIZE);
	if (r > 0 || ft_strchr(store, '\n'))
	{
		retur = funct(&store, buf, fd, &r);
		free(buf);
		if (retur)
			return (retur);
	}
	else
		free(buf);
	if (store != NULL)
	{
		ret = ft_strdup(store);
		free(store);
		store = NULL;
		return (ret);
	}
	return (NULL);
}
#endif