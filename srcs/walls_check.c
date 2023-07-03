/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:46:27 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 20:02:23 by ade-bast         ###   ########.fr       */
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

void	check_coord(t_game *game, int y, int x, int *sizes)
{
	int	i;

	i = 0;
	while (game->world_map[y + 1][i] && i < x)
		i++;
	if (y == 0 || !game->world_map[y + 1] 
		|| x >= sizes[y - 1] || x >= sizes[y + 1]
		|| !game->world_map[y - 1][x] || i < x || !game->world_map[y + 1][x])
		errors(game, 9, game->map);
	else if (game->world_map[y - 1][x] == ' '
		|| game->world_map[y - 1][x] == '\n')
		errors(game, 9, game->world_map[y]);
	else if (game->world_map[y + 1][x] == ' '
		|| game->world_map[y + 1][x] == '\n')
		errors(game, 9, game->world_map[y]);
	else if (x > max_hor(game->world_map, y + 1)
		|| (game->world_map[y - 1] && x > max_hor(game->world_map, y - 1)))
		errors(game, 9, game->world_map[y]);
}

void	bottom(t_game *game, char **map, int *sizes)
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
				check_coord(game, i, j, sizes);
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

void	walls_missing(t_game *game, char *map, int *sizes)
{
	// space_in_map(game);
	walls(game, map);
	bottom(game, game->world_map, sizes);
	new_line_and_open_map(game, map);
}
