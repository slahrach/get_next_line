/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:03:14 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/04 21:40:46 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	l;

	l = ft_strlen(s1);
	ptr = (char *) malloc ((l + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy (ptr, s1, l + 1);
	return (ptr);
}

char	*ft_strnchr(char *s, int c, int *i)
{
	*i = 0;
	while (s[*i] != '\0')
	{
		if (s[(*i)] == (unsigned char)c)
		{
			(*i)++;
			if (s[*i] != '\0')
				return (ft_strdup(&s[*i]));
			return (NULL);
		}
		(*i)++;
	}
	*i = -1;
	return (NULL);
}

size_t	ft_strlcpy( char *dst, char *src, size_t sizedst)
{
	size_t	l;
	size_t	i;

	l = ft_strlen(src);
	i = 0;
	if (sizedst == 0)
		return (l);
	while (src[i] && i < (sizedst - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		b;

	if (s1 == NULL)
		return (ft_strdup(s2));
	i = 0;
	b = 0;
	str = (char *) malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
	{
		str[i] = s2[b];
		i++;
		b++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
