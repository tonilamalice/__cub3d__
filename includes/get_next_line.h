/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:35:31 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/29 17:30:28 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "struct.h"
# include "cub.h"


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
