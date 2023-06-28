/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:13 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/28 18:45:34 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		errors(game, 1, NULL);
	extension_check(game, av[1]);
	read_map(game, av[1]);
	game->s_map = ft_split(game->map, '\n');
	error_map(game, game->map);
	rgb_check(game, game->floor, &game->color_floor);
	rgb_check(game, game->roof, &game->color_roof);
	init_player_pos(game);
	filling_sprite_tab(game);
}
