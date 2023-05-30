/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:41 by arnalove          #+#    #+#             */
/*   Updated: 2023/05/30 17:19:54 by arnalove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void ft_move(t_game *game, t_move *move, int **map)
{
    double olDirX;
    double oldPlaneX;

    if (move->forward)// AVANCER
    {
        if (map[(int)(game->posX + game->dirX * move->moveSpeed)][(int)game->posX] == 0)
            game->posX += game->dirX * move->moveSpeed;
        if (map[(int)game->posX][(int)(game->posY + game->dirY * move->moveSpeed)] == 0)
            game->posY += game->dirY * move->moveSpeed;
    }
    if (move->back)// RECULER
    {
        if (map[(int)(game->posX - game->dirX * move->moveSpeed)][(int)game->posX] == 0)
            game->posX -= game->dirX * move->moveSpeed;
        if (map[(int)game->posX][(int)(game->posY - game->dirY * move->moveSpeed)] == 0)
            game->posY -= game->dirY * move->moveSpeed;
    }
    if (move->turn)// SSX ON TOURNE
    {
        olDirX = game->dirX;
        game->dirX = game->dirX * cos(-move->rotSpeed) - game->dirY * sin(-move->rotSpeed);
        game->dirY = olDirX * sin(-move->rotSpeed) + game->dirY * cos(-move->rotSpeed);
        oldPlaneX = game->planeX;
        game->planeX = game->planeX * cos(-move->rotSpeed) - game->planeY * sin(-move->rotSpeed);
        game->planeY = oldPlaneX * sin(-move->rotSpeed) + game->planeY * cos(-move->rotSpeed);
    }
    if (move->left) // LATERAL GAUCHE
    {
        if (map[(int)(game->posX + game->dirX * move->moveSpeed)][(int)game->posX] == 0)
            game->posX += game->planeX * move->moveSpeed;
        if (map[(int)game->posX][(int)(game->posY + game->dirY * move->moveSpeed)] == 0)
            game->posY += game->planeY * move->moveSpeed;
    }
    if (move->right) // LATERAL DROIT
    {
        if (map[(int)(game->posX - game->dirX * move->moveSpeed)][(int)game->posX] == 0)
            game->posX -= game->planeX * move->moveSpeed;
        if (map[(int)game->posX][(int)(game->posY - game->dirY * move->moveSpeed)] == 0)
            game->posY -= game->planeY * move->moveSpeed;
    }
}