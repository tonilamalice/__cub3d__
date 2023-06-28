/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos_and_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:05 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/28 16:43:06 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub.h"

void	init_player_pos(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (player(game->map[i]))
			game->player = player_coord(game->map, i);
		i++;
	}
}

int	missing_element(t_game *game)
{
	return (!(game->sprite.n_path) || !(game->sprite.s_path)
		|| !(game->sprite.e_path) || !(game->sprite.w_path)
		|| !(game->roof) || !(game->floor));
}

void	rgb_check(t_game *game, char *rgb, int *color)
{
	int		i;
	int		integer;
	char	**cpy;

	i = 0;
	if (missing_element(game))
		errors(game, 12, NULL);
	cpy = ft_split(rgb, ',');
	while (cpy[i])
	{
		integer = ft_atoi_pars(game, cpy[i]);
		if (integer < 0 || integer > 255)
			errors(game, 10, cpy[i]);
		if (i == 0)
			*color += integer * 256 * 256;
		else if (i == 1)
			*color += integer * 256;
		else
			*color += integer;
		i++;
	}
	if (i != 3)
		errors(game, 10, rgb);
	free_split(cpy);
}