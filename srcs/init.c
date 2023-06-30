/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:27 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 14:11:17 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static t_text *init_texture(t_game *game)
{
	t_text *text;

	text = NULL;
	text = malloc(sizeof(t_text));// protection
	text->texFiles = game->sprite.tab_path;
	// printf("test in INIT = %s\n", game->sprite.tab_path[0]);
	// printf("test in INIT = %s\n", text->texFiles[0]);
	text->texHeight = 64;
	text->texHeight = 64;

	text->textures = NULL;
	text->text_array = NULL;
	text->color = 0;
	text->color_floor = game->color_floor;
	text->color_ceiling = game->color_roof;
	return (text);
}

static t_digdifanalyzer *init_dda(void)
{
	t_digdifanalyzer *dda;

	dda = NULL;
	dda = malloc(sizeof(t_digdifanalyzer));// protection
	
	return (dda);
}

static t_rays *init_rays(void)
{
	t_rays *rays;

	rays = NULL;
	rays = malloc(sizeof(t_rays));// protection
	return (rays);
}

static t_move *init_move(void)
{
	t_move *move;
	
	move = NULL;
	move = malloc(sizeof(t_move));// protection
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

int get_player_dir(t_game *game)
{
	if (game->player_dir == 'N')
	{
		game->dirX = -1.0;
		game->dirY = 0.0;
		game->planeX = 0.0;
		game->planeY = 1.0;
	}
	if (game->player_dir == 'S')
	{
		game->dirX = 1.0;
		game->dirY = 0.0;
		game->planeX = 0.0;
		game->planeY = -1.0;
	}
	if (game->player_dir == 'E')
	{
		game->dirX = 0.0;
		game->dirY = 1.0;
		game->planeX = 1.0;
		game->planeY = 0.0;
	}
	if (game->player_dir == 'W')
	{
		game->dirX = 0.0;
		game->dirY = -1.0;
		game->planeX = -1.0;
		game->planeY = 0.0;
	}
	return (0);
}

static t_game	*init_game(int argc, char **argv)
{
	t_game *game;

	game = NULL;
	game = malloc(sizeof(t_game));// protection
	game->screenWidth = WIDTH;
	game->screenHeight = HEIGHT;
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
	get_player_dir(game);
	return (game);
}

t_data *init_data(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	data = malloc(sizeof(t_data));
	open_window(data);// .             protection
	data->game = init_game(argc, argv);
	data->game->move = init_move();
	data->game->rays = init_rays();
	data->game->dda = init_dda();
	data->game->text = init_texture(data->game);
	data->game->dda->img = &data->img;
	return (data);
}
