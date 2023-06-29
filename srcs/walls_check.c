/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:46:27 by achansar          #+#    #+#             */
/*   Updated: 2023/06/29 11:55:27 by achansar         ###   ########.fr       */
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
	if (y == 0 || !game->worldMap[y + 1]
		|| !game->worldMap[y - 1][x] || !game->worldMap[y + 1][x])
		errors(game, 9, game->map);
	else if (game->worldMap[y - 1][x] == ' ' || game->worldMap[y - 1][x] == '\n')
		errors(game, 9, game->worldMap[y]);
	else if (game->worldMap[y + 1][x] == ' ' || game->worldMap[y + 1][x] == '\n')
		errors(game, 9, game->worldMap[y]);
	else if (x > max_hor(game->worldMap, y + 1)
		|| (game->worldMap[y - 1] && x > max_hor(game->worldMap, y - 1)))
		errors(game, 9, game->worldMap[y]);
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
	bottom(game, game->worldMap);
	new_line_and_open_map(game, map);
}
