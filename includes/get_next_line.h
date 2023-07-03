/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:49:00 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:07:57 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "struct.h"
# include "cub.h"
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*read_line(int fd, char *line);
int		read_with_temp(int *nbytes, char **temp, int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*new_line(char *str);
void	new_buffer(char *str, char *buffer);

#endif
