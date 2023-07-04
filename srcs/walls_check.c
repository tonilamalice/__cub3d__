/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:46:27 by achansar          #+#    #+#             */
/*   Updated: 2023/07/04 14:57:41 by ade-bast         ###   ########.fr       */
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
	if (y == 0 || !game->world_map[y + 1]
		|| x >= sizes[y - 1] || x >= sizes[y + 1]
		|| !game->world_map[y - 1][x] || !game->world_map[y + 1][x])
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

void	check_empty_line(t_game *game, int *sizes, int i, int j)
{
	while (game->world_map[i][j])
	{
		if (game->world_map[i][j] == '0' || player(game->world_map[i][j]))
			check_coord(game, i, j, sizes);
		j++;
	}
	if (game->world_map[i + 1] && sizes[i + 1] == 0)
	{
		sizes[i] = 0;
		sizes[i + 1] = game->tmp_size;
	}
	game->map_i += j + 1;
	i++;
}

void	bottom(t_game *game, char **map, int *sizes)
{
	int		i;
	int		j;

	i = 0;
	game->map_i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i + 1])
			game->tmp_size = sizes[i + 1];
		if (game->map[game->map_i + sizes[i] + 1] == '\n')
		{
			sizes[i + 1] = 0;
			while (game->map[game->map_i + sizes[i] + 1 + j] == '\n')
				j++;
			game->map_i += j;
			j = 0;
		}
		check_empty_line(game, sizes, i, j);
		i++;
	}
}

void	walls_missing(t_game *game, char *map, int *sizes)
{
	walls(game, map);
	bottom(game, game->world_map, sizes);
}
