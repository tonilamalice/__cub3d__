/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:53:38 by achansar          #+#    #+#             */
/*   Updated: 2023/05/19 17:00:46 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int ft_dda()
{
    
}

int render(t_data *data, t_game *game, t_move *move, t_rays *rays)
{
    int x;
    int y;
    
    x = 0;
    y = 0;
    if (move->forward || move->back || move->left || move->right || move->turn || move->firstScreen)
    {
        move->back = false;
        
        // screenlock() , utile ? peut etre pour eviter  residus
        // bouge();

        while (x <= game->screenWidth)
        {
            rays->cameraX = (2 * x / WIDTH) - 1;
            rays->rayPosX = game->posX;
            rays->rayPosY = game->posY;
            rays->rayDirX = game->dirX + game->planeX * rays->cameraX;
            rays->rayDirY = game->dirY + game->planeY * rays->cameraX;
        }
        
        // screenUnlock();
    }
}
