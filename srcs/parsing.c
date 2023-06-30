/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:02:16 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 17:18:37 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		errors(game, 1, NULL);
	extension_check(game, av[1]);
	read_map(game, av[1]);
	game->worldMap = ft_split(game->map, '\n');
	error_map(game, game->map);
	rgb_check(game, game->floor, &game->color_floor);
	rgb_check(game, game->roof, &game->color_roof);
	init_player_pos(game);
	filling_sprite_tab(game);
	free(game->map);
}
