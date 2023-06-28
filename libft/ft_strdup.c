/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:24:50 by achansar          #+#    #+#             */
/*   Updated: 2023/06/27 15:12:46 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
