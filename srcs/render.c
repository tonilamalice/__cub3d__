/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:53:38 by achansar          #+#    #+#             */
/*   Updated: 2023/05/24 17:21:05 by arnalove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int ft_dda(t_game *game, t_rays *rays, t_digdifanalyzer *dda)
{
    dda->mapX = (int)rays->rayPosX;
    dda->mapY = (int)rays->rayPosY;
    dda->deltaDistX = sqrt(1 + (rays->rayDirY * rays->rayDirY) / (rays->rayDirX * rays->rayDirX));
    dda->deltaDistY = sqrt(1 + (rays->rayDirX * rays->rayDirX) / (rays->rayDirY * rays->rayDirY));
    dda->hit = 0;
    if (rays->rayDirX < 0)
    {
        dda->stepX = -1;
        dda->sideDistX = (rays->rayPosX - dda->mapX) * dda->deltaDistX;
    }
    else
    {
        dda->stepX = 1;
        dda->sideDistX = (dda->mapX + 1.0 - rays->rayPosX) * dda->deltaDistX;
    }
    if (rays->rayDirY < 0)
    {
        dda->stepY = -1;
        dda->sideDistY = (rays->rayPosY - dda->mapY) * dda->deltaDistY;
    }
    else
    {
        dda->stepY = 1;
        dda->sideDistY = (dda->mapY + 1.0 - rays->rayPosY) * dda->deltaDistY;
    }// 25 lignes !

    // performing the DDA
    while (dda->hit == 0)
    {
        printf("times of hit\n");
        if (dda->sideDistX < dda->sideDistY)
        {
            dda->sideDistX += dda->sideDistX;
            dda->mapX += dda->stepX;
            dda->side = 0;
        }
        else
        {
            dda->sideDistY += dda->sideDistY;
            dda->mapY += dda->stepY;
            dda->side = 1;
        }
        if (game->worldMap[dda->mapX][dda->mapY] > 0)
        {
            printf("map[%d][%d] = %d\n", dda->mapX, dda->mapY, game->worldMap[dda->mapX][dda->mapY]);
            dda->hit = 1;
        }
    }
    printf("Infos\nmapX = %d / rayPosX = %f / stepX = %f / rayDirx = %f\n", dda->mapX, rays->rayPosX, dda->stepX, rays->rayDirX);
    //Correct the dist
    if (dda->side == 0)
        dda->perpWallDist = fabs((dda->mapX - rays->rayPosX + (1 - dda->stepX) / 2) / rays->rayDirX);
    else
        dda->perpWallDist = fabs((dda->mapY - rays->rayPosY + (1 - dda->stepY) / 2) / rays->rayDirY);
    printf("End of DDA : perpWallDist = %f\n", dda->perpWallDist);
    return (0);
}

int render(t_data *data, t_game *game, t_move *move, t_rays *rays)
{
    int x;
    
    x = 0;
    if (move->forward || move->back || move->left || move->right || move->turn || move->firstscreen)
    {
        move->firstscreen = false;
        
        // screenlock() , utile ? peut etre pour eviter  residus
        // bouge();

        // besoin bzero() avant ?
        while (x <= game->screenWidth)
        {
            rays->cameraX = (2 * x / WIDTH) - 1;
            rays->rayPosX = game->posX;
            printf("posX 1 = %f-%f\n", game->posX, game->posY);
            rays->rayPosY = game->posY;
            rays->rayDirX = game->dirX + game->planeX * rays->cameraX;
            rays->rayDirY = game->dirY + game->planeY * rays->cameraX;

            ft_dda(game, rays, game->dda);
            drawloop(game->dda, x);
            x++;
        }
        mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
        printf("right after puting image\n");
        // screenUnlock();
    }
    return (0);
}
