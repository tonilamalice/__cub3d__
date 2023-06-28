/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:29:56 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/28 16:43:12 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/cub.h"

void	walls(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '0' || player(map[i]))
		{
			if (map[i - 1] && (map[i - 1] == ' ' || map[i - 1] == '\n'))
				errors(game, 9, map);
			else if ((map[i + 1] && (map[i + 1] == '\n'
						|| map[i + 1] == ' ')) || !map[i + 1])
				errors(game, 9, map);
		}
		i++;
	}
}

void	check_coord(t_game *game, int y, int x)
{
	if (y == 0 || !game->s_map[y + 1]
		|| !game->s_map[y - 1][x] || !game->s_map[y + 1][x])
		errors(game, 9, game->map);
	else if (game->s_map[y - 1][x] == ' ' || game->s_map[y - 1][x] == '\n')
		errors(game, 9, game->s_map[y]);
	else if (game->s_map[y + 1][x] == ' ' || game->s_map[y + 1][x] == '\n')
		errors(game, 9, game->s_map[y]);
	else if (x > max_hor(game->s_map, y + 1)
		|| (game->s_map[y - 1] && x > max_hor(game->s_map, y - 1)))
		errors(game, 9, game->s_map[y]);
}

void	bottom(t_game *game, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || player(map[i][j]))
				check_coord(game, i, j);
			j++;
		}
		i++;
	}
}

void	new_line_and_open_map(t_game *game, char *map)
{
	int	i;
	int	n;

	i = 0;
	while (map[i])
	{
		n = i;
		while ((map[i] == '0' || player(map[i])) && map[n])
		{
			n++;
			if (map[n] == '\n' && map[n + 1] && map[n + 1] == '\n')
				errors(game, 9, map);
			else if (map[n] == '\n' && map[n + 1] && map[n + 1] != '\n')
				break ;
		}
		i++;
	}
}

void	walls_missing(t_game *game, char *map)
{

	walls(game, map);
	bottom(game, game->s_map);
	new_line_and_open_map(game, map);
}
