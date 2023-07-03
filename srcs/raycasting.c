/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:39:14 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 19:38:57 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	get_distance(t_rays *rays, t_digdifanalyzer *dda)
{
	if (rays->raydir_x < 0)
	{
		dda->step_x = -1;
		dda->sidedist_x = (rays->raypos_x - dda->map_x) * dda->deltadist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->sidedist_x = (dda->map_x + 1.0 - rays->raypos_x) * dda->deltadist_x;
	}
	if (rays->raydir_y < 0)
	{
		dda->step_y = -1;
		dda->sidedist_y = (rays->raypos_y - dda->map_y) * dda->deltadist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->sidedist_y = (dda->map_y + 1.0 - rays->raypos_y) * dda->deltadist_y;
	}
	return (0);
}

static	int	distance_correction(t_rays *rays, t_digdifanalyzer *dda)
{
	if (dda->side == 0)
		dda->wall_dist = fabs((dda->map_x - rays->raypos_x
					+ (1 - dda->step_x) / 2) / rays->raydir_x);
	else
		dda->wall_dist = fabs((dda->map_y - rays->raypos_y
					+ (1 - dda->step_y) / 2) / rays->raydir_y);
	return (0);
}

static	int	get_rays(t_game *game, t_rays *rays, t_digdifanalyzer *dda)
{
	rays->cam_x = (2 * (double)game->dda->x / (double)WIDTH) - 1;
	rays->raypos_x = game->pos_x;
	rays->raypos_y = game->pos_y;
	rays->raydir_x = game->dir_x + game->plane_x * rays->cam_x;
	rays->raydir_y = game->dir_y + game->plane_y * rays->cam_x;
	dda->map_x = (int)rays->raypos_x;
	dda->map_y = (int)rays->raypos_y;
	dda->deltadist_x = sqrt(1 + (rays->raydir_y * rays->raydir_y)
			/ (rays->raydir_x * rays->raydir_x));
	dda->deltadist_y = sqrt(1 + (rays->raydir_x * rays->raydir_x)
			/ (rays->raydir_y * rays->raydir_y));
	dda->hit = 0;
	return (0);
}

int	ft_dda(t_game *game, t_rays *rays, t_digdifanalyzer *dda)
{
	get_rays(game, rays, dda);
	get_distance(rays, dda);
	while (dda->hit == 0)
	{
		if (dda->sidedist_x < dda->sidedist_y)
		{
			dda->sidedist_x += dda->deltadist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->sidedist_y += dda->deltadist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		// printf("%d %d\n", (int)dda->map_x, (int)dda->map_y);
		if (game->world_map[(int)dda->map_x][(int)dda->map_y] == '1')
			dda->hit = 1;
	}
	distance_correction(rays, dda);
	return (0);
}
