/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:32 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/28 16:43:16 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	check_only_digit(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(str[i] >= 9 && str[i] <= 13)
			&& str[i] != 32 && str[i] != '+')
			errors(game, 10, (char *)str);
		i++;
	}
}

int	ft_atoi_pars(t_game *game, char *str)
{
	int			i;
	int			s;
	long long	res;

	i = 0;
	res = 0;
	s = 1;
	check_only_digit(game, str);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		if (res < 0)
			errors(game, 10, (char *)str);
	}
	res *= s;
	return (res);
}
