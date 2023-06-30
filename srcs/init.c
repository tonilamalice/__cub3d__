/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:27 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 17:12:29 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static t_text *init_texture(t_game *game)
{
	t_text *text;

	text = NULL;
	text = malloc(sizeof(t_text));
	if (!text)
		return (text);
	text->texFiles = NULL;
	text->textures = NULL;
	text->text_array = NULL;
	text->texHeight = 64;
	text->texHeight = 64;
	text->color = 0;
	text->texFiles = game->sprite.tab_path;
	text->color_floor = game->color_floor;
	text->color_ceiling = game->color_roof;
	return (text);
}

static t_digdifanalyzer *init_dda(void)
{
	t_digdifanalyzer *dda;

	dda = NULL;
	dda = malloc(sizeof(t_digdifanalyzer));
	return (dda);
}

static t_rays *init_rays(void)
{
	t_rays *rays;

	rays = NULL;
	rays = malloc(sizeof(t_rays));
	return (rays);
}

static t_move *init_move(void)
{
	t_move *move;
	
	move = NULL;
	move = malloc(sizeof(t_move));
	if (!move)
		return (move);
	move->moveSpeed = 0.1;
	move->rotSpeed = 0.05;
	move->forward = false;
	move->back = false;
	move->left = false;
	move->right = false;
	move->turn = false;
	move->firstscreen = true;
	return (move);
}

int get_player_dirEW(t_game *game)
{
	if (game->player_dir == 'E')
	{
		game->dirX = 0.0;
		game->dirY = 1.0;
		game->planeX = 1.0;
		game->planeY = 0.0;
	}
	else if (game->player_dir == 'W')
	{
		game->dirX = 0.0;
		game->dirY = -1.0;
		game->planeX = -1.0;
		game->planeY = 0.0;
	}
	return (0);
}

int get_player_dirNS(t_game *game)
{
	if (game->player_dir == 'N')
	{
		game->dirX = -1.0;
		game->dirY = 0.0;
		game->planeX = 0.0;
		game->planeY = 1.0;
	}
	else if (game->player_dir == 'S')
	{
		game->dirX = 1.0;
		game->dirY = 0.0;
		game->planeX = 0.0;
		game->planeY = -1.0;
	}
	else
		get_player_dirEW(game);
	return (0);
}

int set_game_structs(t_game *game)
{
	get_player_dirNS(game);
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
	t_game *game;

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
	game->posX = game->player.y;
	game->posY = game->player.x;
	set_game_structs(game);
	return (game);
}

t_data *init_data(int argc, char **argv)
{
	t_data *data;

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
