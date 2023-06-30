/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:44:57 by achansar          #+#    #+#             */
/*   Updated: 2023/06/29 17:19:19 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	extension_check(t_game *game, char *av)
{
	int	len;

	len = ft_strlen(av);
	if (av[len - 1] == 'b' && av[len - 2] == 'u'
		&& av[len - 3] == 'c' && av[len - 4] == '.')
		;
	else
		errors(game, 3, av);
}

void	number_of_characters(t_game *game, char *map)
{
	int	i;
	int	character;

	i = 0;
	character = 0;
	while (map[i])
	{
		if (player(map[i]))
		{
			game->player_dir = map[i];
			character++;
		}
		i++;
	}
	if (character != 1)
		errors(game, 1, map);
}

void	other_character(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!player(map[i]) && map[i] != '0' && map[i] != '1'
			&& map[i] != '\n' && map[i] != ' ')
			errors(game, 8, &map[i]);
		i++;
	}
}

void	error_map(t_game *game, char *map)
{
	other_character(game, map);
	number_of_characters(game, map);
	walls_missing(game, map);
}
