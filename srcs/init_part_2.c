/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_part_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:08:33 by ade-bast          #+#    #+#             */
/*   Updated: 2023/07/03 15:14:45 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	get_player_dirns(t_game *game)
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
		get_player_direw(game);
	return (0);
}

int	set_game_structs(t_game *game)
{
	get_player_dirns(game);
	game->move = NULL;
	game->rays = NULL;
	game->dda = NULL;
	game->text = NULL;
	game->move = init_move();
	game->rays = init_rays();
	game->dda = init_dda();
	game->text = init_texture(game);
	if (!game->move || !game->rays || !game->dda || !game->text)
		free_game(game);
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
