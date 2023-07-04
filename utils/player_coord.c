/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:44 by ade-bast          #+#    #+#             */
/*   Updated: 2023/07/03 19:47:10 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_pos	player_coord(char *map, int i)
{
	int		j;
	int		count;
	t_pos	pos;

	j = i;
	count = 0;
	while (j >= 0)
	{
		if (map[j] == '\n' && map[j + 1] != '\n')
				count++;
		if (map[j] == '\n' && count == 1)
			pos.x = i - j - 1 + 0.05;
		j--;
	}	
	pos.y = count + 0.05;
	return (pos);
}

int	max_vert(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

int	max_hor(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
		j++;
	return (j);
}
