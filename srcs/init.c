/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:27 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 15:19:46 by ade-bast         ###   ########.fr       */
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

int	get_player_direw(t_game *game)
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
		game->plane_x = 0.0;
	}
	return (0);
}
