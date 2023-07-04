/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:08:04 by achansar          #+#    #+#             */
/*   Updated: 2023/07/04 11:19:16 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	parsing(t_game *game, int ac, char **av)
{
	int	map_size;
	int	*sizes;

	if (ac != 2)
		errors(game, 1, NULL);
	map_size = 0;
	extension_check(game, av[1]);
	read_map(game, av[1]);
	game->world_map = ft_split(game->map, '\n');
	while (game->world_map[map_size++])
		;
	sizes = malloc(sizeof(int) * map_size);
	if (!sizes)
		exit(EXIT_FAILURE);
	map_size = -1;
	while (game->world_map[++map_size])
		sizes[map_size] = ft_strlen(game->world_map[map_size]);
	error_map(game, game->map, sizes);
	free(sizes);
	rgb_check(game, game->floor, &game->color_floor);
	rgb_check(game, game->roof, &game->color_roof);
	init_player_pos(game);
	filling_sprite_tab(game);
	free(game->map);
}
