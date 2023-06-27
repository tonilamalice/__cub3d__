/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:27 by achansar          #+#    #+#             */
/*   Updated: 2023/06/27 19:11:49 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static t_text *init_texture(void)
{
	t_text *text;

	text = NULL;
	text = malloc(sizeof(t_text));// protection
	text->texFiles = ft_strdup("texture/mossy.xpm");
	text->texHeight = 64;
	text->texHeight = 64;

	text->textures = NULL;
	text->text_array = NULL;
	text->color = 0;
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

static t_game	*init_game(void)
{
	t_game *game;

	game = NULL;
	game = malloc(sizeof(t_game));// protection
	game->posX = 11.0;
	game->posY = 10.0;
	game->dirX = -1.0;
	game->dirY = 0.0;
	game->planeX = 0.0;
	game->planeY = -1.0;
	game->screenWidth = WIDTH;
	game->screenHeight = HEIGHT;
	game->worldMap = ft_upscale(24, UPSCALE);
	game->move = init_move();
	game->rays = init_rays();
	game->dda = init_dda();
	game->text = init_texture();
	return (game);
}

t_data *init_data(void)
{
	t_data *data;

	data = NULL;
	data = malloc(sizeof(t_data));
	open_window(data);// .             protection
	data->game = init_game();
	data->game->dda->img = &data->img;
	return (data);
}
