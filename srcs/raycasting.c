/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:39:14 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 17:23:04 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int get_distance(t_rays *rays, t_digdifanalyzer *dda)
{
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
	}
	return (0);
}

static	int	distance_correction(t_rays *rays, t_digdifanalyzer *dda)
{
	if (dda->side == 0)
		dda->perpWallDist = fabs((dda->mapX - rays->rayPosX
			+ (1 - dda->stepX) / 2) / rays->rayDirX);
	else
		dda->perpWallDist = fabs((dda->mapY - rays->rayPosY
			+ (1 - dda->stepY) / 2) / rays->rayDirY);
	return (0);
}

static	int	get_rays(t_game *game, t_rays *rays, t_digdifanalyzer *dda)
{
	rays->cameraX = (2 * (double)game->dda->x / (double)WIDTH) - 1;
	rays->rayPosX = game->posX;
	rays->rayPosY = game->posY;
	rays->rayDirX = game->dirX + game->planeX * rays->cameraX;
	rays->rayDirY = game->dirY + game->planeY * rays->cameraX;
	dda->mapX = (int)rays->rayPosX;
	dda->mapY = (int)rays->rayPosY;
	dda->deltaDistX = sqrt(1 + (rays->rayDirY * rays->rayDirY)
		/ (rays->rayDirX * rays->rayDirX));
	dda->deltaDistY = sqrt(1 + (rays->rayDirX * rays->rayDirX)
		/ (rays->rayDirY * rays->rayDirY));
	dda->hit = 0;
	return (0);
}

int	ft_dda(t_game *game, t_rays *rays, t_digdifanalyzer *dda)
{
	get_rays(game, rays, dda);
	get_distance(rays, dda);
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
		if (game->worldMap[(int)dda->mapX][(int)dda->mapY] == '1')
			dda->hit = 1;
	}
	distance_correction(rays, dda);
	return (0);
}
