/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:23 by ade-bast          #+#    #+#             */
/*   Updated: 2023/07/03 14:06:06 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (*s == cc)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	count;
	char	*ptr;

	i = 0;
	j = 0;
	count = 0;
	if (!s1 || !s2)
		return (NULL);
	count = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		exit(EXIT_FAILURE);
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free (s1);
	return (ptr);
}
