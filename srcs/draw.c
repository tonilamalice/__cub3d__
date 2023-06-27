/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:10:43 by achansar          #+#    #+#             */
/*   Updated: 2023/06/27 19:04:54 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	// printf("in put_pixel\n");
	// printf("coloring in [%d][%d]\n", x, y);
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		pixel = img->addr + (img->szline * y + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

static int draw_column(t_digdifanalyzer *dda, t_text *text, t_rays *rays, int lineH)
{
	(void)lineH;
	int y;

	if (dda->side == 1)
	{
		text->wallX = rays->rayPosX + ((dda->mapY - rays->rayPosY + (1 - dda->stepY) / 2) / rays->rayDirY) * rays->rayDirX;
		// img_pix_put(dda->img, dda->x, y, 0xCCCCCC);
	}
	else
	{
		text->wallX = rays->rayPosY + ((dda->mapX - rays->rayPosX + (1 - dda->stepX) / 2) / rays->rayDirX) * rays->rayDirY;
		// img_pix_put(dda->img, dda->x, y, 0xf2f2f2);
	}
	text->wallX -= floor(text->wallX);
	
	text->texX = (int)(text->wallX * text->texWidth);
	if (dda->side == 0 && rays->rayDirX > 0)
		text->texX = text->texWidth - text->texX - 1;
	if (dda->side == 0 && rays->rayDirY < 0)
		text->texX = text->texWidth - text->texX - 1;


	y = dda->start;
	while (y < dda->end)
	{

		text->texY = (y * 2 - HEIGHT + lineH) * (text->texHeight / 2) / lineH;
		text->color = 1;
		text->color = text->text_array[text->texX + text->texY * text->texWidth];//     -> ici pour ajouter un index
		img_pix_put(dda->img, dda->x, y, text->color);
		y++;
	}
	if (dda->end < 0)
		dda->end = HEIGHT;
	y = dda->end;
	while (y < HEIGHT)
	{
		img_pix_put(dda->img, dda->x, y, 0xcc0000);
		img_pix_put(dda->img, dda->x, HEIGHT-y-1, 0x006666);
		y++;
	}
	return (0);
}

int drawloop(t_game *game, t_digdifanalyzer *dda)
{
	int lineH;

	lineH = abs((int)((double)HEIGHT / dda->perpWallDist));
	dda->start = -lineH / 2 + (double)HEIGHT / 2;
	dda->end = lineH / 2 + (double)HEIGHT / 2;

	if (dda->start < 0)
		dda->start = 0;
	if (dda->end >= HEIGHT)
		dda->end = HEIGHT - 1;

	// printf("before draw_column\n");
	draw_column(dda, game->text, game->rays, lineH);
	return (0);
}
