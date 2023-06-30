/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:10:43 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 16:14:02 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		pixel = img->addr + (img->szline * y + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

static int	draw_column(t_digdifanalyzer *dda, t_text *text, t_rays *rays)
{
	int y = 0;

	if (dda->side == 1)
		text->wallX = rays->rayPosX + dda->perpWallDist * rays->rayDirX;
	else
		text->wallX = rays->rayPosY + dda->perpWallDist * rays->rayDirY;
	text->wallX -= floor(text->wallX);
	text->texX = (int)(text->wallX * text->texWidth);
	if (dda->side == 0 && rays->rayDirX > 0)
		text->texX = text->texWidth - text->texX - 1;
	if (dda->side == 0 && rays->rayDirY < 0)
		text->texX = text->texWidth - text->texX - 1;
	y += put_textures(dda, rays, text, y);
	color_floor_ceiling(dda, text, y);
	return (0);
}

int	drawloop(t_game *game, t_digdifanalyzer *dda)
{
	dda->lineH = abs((int)((double)HEIGHT / dda->perpWallDist));
	dda->start = -dda->lineH / 2 + (double)HEIGHT / 2;
	dda->end = dda->lineH / 2 + (double)HEIGHT / 2;

	if (dda->start < 0)
		dda->start = 0;
	if (dda->end >= HEIGHT)
		dda->end = HEIGHT - 1;
	draw_column(dda, game->text, game->rays);
	return (0);
}
