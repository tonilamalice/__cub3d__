/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:40 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/28 16:43:23 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

char	*ft_strdup_pars(const char *src)
{
	int		i;
	char	*ptr;

	i = 0;
	while (src[i])
		i++;
	ptr = malloc(sizeof(src[0]) * i + 1);
	if (!ptr)
		exit(EXIT_FAILURE);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t			i;
// 	unsigned char	*ub;
// 	unsigned char	uc;

// 	ub = b;
// 	uc = c;
// 	i = 0;
// 	while (i < len)
// 	{
// 		ub[i] = uc;
// 		i++;
// 	}
// 	return (ub);
// }
