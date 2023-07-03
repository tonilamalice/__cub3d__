/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:10:43 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:03:18 by achansar         ###   ########.fr       */
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
	int	y;

	y = 0;
	if (dda->side == 1)
		text->wall_x = rays->raypos_x + dda->wall_dist * rays->raydir_x;
	else
		text->wall_x = rays->raypos_y + dda->wall_dist * rays->raydir_y;
	text->wall_x -= floor(text->wall_x);
	text->tex_x = (int)(text->wall_x * text->t_width);
	if (dda->side == 0 && rays->raydir_x > 0)
		text->tex_x = text->t_width - text->tex_x - 1;
	if (dda->side == 0 && rays->raydir_y < 0)
		text->tex_x = text->t_width - text->tex_x - 1;
	y += put_textures(dda, rays, text, y);
	color_floor_ceiling(dda, text, y);
	return (0);
}

int	drawloop(t_game *game, t_digdifanalyzer *dda)
{
	dda->line_h = abs((int)((double)HEIGHT / dda->wall_dist));
	dda->start = -dda->line_h / 2 + (double)HEIGHT / 2;
	dda->end = dda->line_h / 2 + (double)HEIGHT / 2;
	if (dda->start < 0)
		dda->start = 0;
	if (dda->end >= HEIGHT)
		dda->end = HEIGHT - 1;
	draw_column(dda, game->text, game->rays);
	return (0);
}
