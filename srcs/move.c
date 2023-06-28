/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:41 by arnalove          #+#    #+#             */
/*   Updated: 2023/06/28 17:53:46 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void mv_forward(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->posX + game->dirX * move->moveSpeed)][(int)game->posY] == '0')
		game->posX += game->dirX * move->moveSpeed;
	if (map[(int)game->posX][(int)(game->posY + game->dirY * move->moveSpeed)] == '0')
		game->posY += game->dirY * move->moveSpeed;
}

static void mv_back(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->posX - game->dirX * move->moveSpeed)][(int)game->posY] == '0')
		game->posX -= game->dirX * move->moveSpeed;
	if (map[(int)game->posX][(int)(game->posY - game->dirY * move->moveSpeed)] == '0')
		game->posY -= game->dirY * move->moveSpeed;
}

static void	mv_left(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->posX + game->dirX * move->moveSpeed)][(int)game->posY] == '0')
		game->posX += game->planeX * move->moveSpeed;
	if (map[(int)game->posX][(int)(game->posY + game->dirY * move->moveSpeed)] == '0')
		game->posY += game->planeY * move->moveSpeed;
}

static void	mv_right(t_game *game, t_move *move, char **map)
{
	if (map[(int)(game->posX - game->dirX * move->moveSpeed)][(int)game->posY] == '0')
		game->posX -= game->planeX * move->moveSpeed;
	if (map[(int)game->posX][(int)(game->posY - game->dirY * move->moveSpeed)] == '0')
		game->posY -= game->planeY * move->moveSpeed;
}

void ft_move(t_game *game, t_move *move, char **map)
{
	double olDirX;
	double oldPlaneX;
	
	if (move->forward)// AVANCER
		mv_forward(game, move, map);
	if (move->back)// RECULER
		mv_back(game, move, map);
	if (move->right) // LATERAL GAUCHE
		mv_left(game, move, map);
	if (move->left) // LATERAL DROIT
		mv_right(game, move, map);

	if (move->turn)// SSX ON TOURNE
	{
		olDirX = game->dirX;
		game->dirX = game->dirX * cos(-move->rotSpeed) - game->dirY * sin(-move->rotSpeed);
		game->dirY = olDirX * sin(-move->rotSpeed) + game->dirY * cos(-move->rotSpeed);
		oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(-move->rotSpeed) - game->planeY * sin(-move->rotSpeed);
		game->planeY = oldPlaneX * sin(-move->rotSpeed) + game->planeY * cos(-move->rotSpeed);
	}
}
