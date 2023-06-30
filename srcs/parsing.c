/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:08:04 by achansar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/29 14:59:34 by achansar         ###   ########.fr       */
=======
/*   Updated: 2023/06/29 17:34:48 by ade-bast         ###   ########.fr       */
>>>>>>> edea460bf2fa37ffd1fa0cc861a1712b989855ce
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
}
