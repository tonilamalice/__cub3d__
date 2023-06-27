/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:53:38 by achansar          #+#    #+#             */
/*   Updated: 2023/06/27 18:36:11 by achansar         ###   ########.fr       */
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
        if (dda->sideDistX < dda->sideDistY)
        {
            dda->sideDistX += dda->deltaDistX;
            dda->mapX += dda->stepX;
            dda->side = 0;
        }
        else
        {
            dda->sideDistY += dda->deltaDistY;
            dda->mapY += dda->stepY;
            dda->side = 1;
        }
        if (game->worldMap[(int)dda->mapX][(int)dda->mapY] >= 1)
        {
            dda->hit = 1;
        }
    }
    //Correct the dist
    if (dda->side == 0)
        dda->perpWallDist = fabs((dda->mapX - rays->rayPosX + (1 - dda->stepX) / 2) / rays->rayDirX);
    else
        dda->perpWallDist = fabs((dda->mapY - rays->rayPosY + (1 - dda->stepY) / 2) / rays->rayDirY);
    return (0);
}

int render(t_data *data, t_game *game, t_move *move, t_rays *rays)
{
    // int x;
    
    game->dda->x = 0;
    if (move->forward || move->back || move->left || move->right || move->turn || move->firstscreen)
    {
        move->firstscreen = false;

        ft_move(game, move, game->worldMap);
        printf("pos = [%f][%f]\n", game->posX, game->posY);
        ft_bzero(data->img.addr, WIDTH * HEIGHT * sizeof(int));
        while (game->dda->x <= game->screenWidth)
        {
            rays->cameraX = (2 * (double)game->dda->x / (double)WIDTH) - 1;
            rays->rayPosX = game->posX;
            rays->rayPosY = game->posY;
            rays->rayDirX = game->dirX + game->planeX * rays->cameraX;
            rays->rayDirY = game->dirY + game->planeY * rays->cameraX;

            
            ft_dda(game, rays, game->dda);
            // get_texture_pos();
            // get_texture_color();
            drawloop(game, game->dda);
            game->dda->x++;
        }
        mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    }
    return (0);
}

int call_to_render(t_data *data)
{
    render(data, data->game, data->game->move, data->game->rays);
    return (0);
}
