/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:30:37 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:05:06 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static	t_text	*init_texture(t_game *game)
{
	t_text	*text;

	text = NULL;
	text = malloc(sizeof(t_text));
	if (!text)
		return (text);
	text->t_files = NULL;
	text->textures = NULL;
	text->text_array = NULL;
	text->t_height = 64;
	text->t_height = 64;
	text->color = 0;
	text->t_files = game->sprite.tab_path;
	text->color_floor = game->color_floor;
	text->color_ceiling = game->color_roof;
	return (text);
}

static	t_digdifanalyzer	*init_dda(void)
{
	t_digdifanalyzer	*dda;

	dda = NULL;
	dda = malloc(sizeof(t_digdifanalyzer));
	return (dda);
}

static	t_rays	*init_rays(void)
{
	t_rays	*rays;

	rays = NULL;
	rays = malloc(sizeof(t_rays));
	return (rays);
}

static	t_move	*init_move(void)
{
	t_move	*move;

	move = NULL;
	move = malloc(sizeof(t_move));
	if (!move)
		return (move);
	move->movespeed = 0.1;
	move->rotspeed = 0.05;
	move->forward = false;
	move->back = false;
	move->left = false;
	move->right = false;
	move->turn = false;
	move->firstscreen = true;
	return (move);
}

int	set_game_structs(t_game *game)
{
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
