/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:41 by arnalove          #+#    #+#             */
/*   Updated: 2023/05/25 18:18:03 by arnalove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void ft_move(t_game *game, t_move *move, int **map)
{
    double olDirX;
    double olPlaneX;

    printf("in move function\n");
    if (move->forward)// AVANCER
    {
        if (map[(int)(game->posX + game->dirX * move->moveSpeed)][(int)game->posX] == 0)
            game->posX += game->dirX * move->moveSpeed;
        if (map[(int)game->posX][(int)(game->posY + game->dirY * move->moveSpeed)] == 0)
            game->posY += game->dirY * move->moveSpeed;
    }
    // if (move->back)// RECULER
    // {

    // }
}