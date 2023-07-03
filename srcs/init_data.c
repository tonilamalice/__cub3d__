/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:27 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:04:24 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	get_player_dir_ew(t_game *game)
{
	if (game->player_dir == 'E')
	{
		game->dir_x = 0.0;
		game->dir_y = 1.0;
		game->plane_x = 1.0;
		game->plane_y = 0.0;
	}
	else if (game->player_dir == 'W')
	{
		game->dir_x = 0.0;
		game->dir_y = -1.0;
		game->plane_x = -1.0;
		game->plane_y = 0.0;
	}
	return (0);
}

static int	get_player_dir_ns(t_game *game)
{
	if (game->player_dir == 'N')
	{
		game->dir_x = -1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = 1.0;
	}
	else if (game->player_dir == 'S')
	{
		game->dir_x = 1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = -1.0;
	}
	else
		get_player_dir_ew(game);
	return (0);
}

static t_game	*init_game(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	game = malloc(sizeof(t_game));
	if (!game)
		return (game);
	game->sprite.n_path = NULL;
	game->sprite.s_path = NULL;
	game->sprite.e_path = NULL;
	game->sprite.w_path = NULL;
	game->roof = NULL;
	game->floor = NULL;
	game->color_floor = 0;
	game->color_roof = 0;
	parsing(game, argc, argv);
	game->pos_x = game->player.y;
	game->pos_y = game->player.x;
	get_player_dir_ns(game);
	set_game_structs(game);
	return (game);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		return (data);
	data->game = NULL;
	data->game = init_game(argc, argv);
	if (!data->game)
		destroy(data);
	data->game->dda->img = &data->img;
	data->mlx = NULL;
	data->img.img = NULL;
	if (open_window(data))
		destroy(data);
	return (data);
}
