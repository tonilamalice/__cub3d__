/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:41 by arnalove          #+#    #+#             */
/*   Updated: 2023/07/03 13:05:06 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static	void	mv_forward(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->pos_x + game->dir_x * move->movespeed)]
		[(int)game->pos_y] != '1')
		game->pos_x += game->dir_x * move->movespeed;
	if (map[(int)game->pos_x]
		[(int)(game->pos_y + game->dir_y * move->movespeed)] != '1')
		game->pos_y += game->dir_y * move->movespeed;
}

static	void	mv_back(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->pos_x - game->dir_x * move->movespeed)]
		[(int)game->pos_y] != '1')
		game->pos_x -= game->dir_x * move->movespeed;
	if (map[(int)game->pos_x]
		[(int)(game->pos_y - game->dir_y * move->movespeed)] != '1')
		game->pos_y -= game->dir_y * move->movespeed;
}

static void	mv_left(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->pos_x + game->plane_x * move->movespeed)]
		[(int)game->pos_y] != '1')
		game->pos_x += game->plane_x * move->movespeed;
	if (map[(int)game->pos_x]
		[(int)(game->pos_y + game->plane_y * move->movespeed)] != '1')
		game->pos_y += game->plane_y * move->movespeed;
}

static void	mv_right(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->pos_x - game->plane_x * move->movespeed)]
		[(int)game->pos_y] != '1')
		game->pos_x -= game->plane_x * move->movespeed;
	if (map[(int)game->pos_x]
		[(int)(game->pos_y - game->plane_y * move->movespeed)] != '1')
		game->pos_y -= game->plane_y * move->movespeed;
}

void	ft_move(t_game *game, t_move *move, char **map)
{
	double	oldir_x;
	double	oldplane_x;

	if (move->forward)
		mv_forward(game, move, map);
	if (move->back)
		mv_back(game, move, map);
	if (move->right)
		mv_left(game, move, map);
	if (move->left)
		mv_right(game, move, map);
	if (move->turn)
	{
		oldir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(-move->rotspeed)
			- game->dir_y * sin(-move->rotspeed);
		game->dir_y = oldir_x * sin(-move->rotspeed)
			+ game->dir_y * cos(-move->rotspeed);
		oldplane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(-move->rotspeed)
			- game->plane_y * sin(-move->rotspeed);
		game->plane_y = oldplane_x * sin(-move->rotspeed)
			+ game->plane_y * cos(-move->rotspeed);
	}
}
