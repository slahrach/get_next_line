/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:03:37 by slahrach          #+#    #+#             */
/*   Updated: 2021/12/04 21:40:27 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(char *s);
char		*ft_strnchr(char *s, int c, int *i);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
size_t		ft_strlcpy(char *dst, char *src, size_t sizedst);
char		*get_next_line(int fd);
#endif