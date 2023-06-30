/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:10:30 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 16:44:46 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	test_delete_this(t_digdifanalyzer *dda, t_text *text)
{
	int	y;
	int	x;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			img_pix_put(dda->img, x, y, text->color_floor);
			img_pix_put(dda->img, x, HEIGHT - y - 1, text->color_ceiling);
			x++;
		}
			y++;
	}
}

int	color_floor_ceiling(t_digdifanalyzer *dda, t_text *text, int y)
{
	if (dda->end < 0)
		dda->end = HEIGHT;
	y = dda->end;
	while (y < HEIGHT)
	{
		img_pix_put(dda->img, dda->x, y, text->color_floor);
		img_pix_put(dda->img, dda->x, HEIGHT - y - 1, text->color_ceiling);
		y++;
	}
	return (0);
}

int	put_textures(t_digdifanalyzer *dda, t_rays *rays, t_text *text, int y)
{
	y = dda->start;
	while (y < dda->end)
	{
		text->texY = (int)(y * 2 - HEIGHT + dda->lineH) 
			* (text->texHeight / 2) / dda->lineH;
		if (dda->side == 0 && rays->rayDirX > 0)
			text->color = 0;
		if (dda->side == 0 && rays->rayDirX < 0)
			text->color = 1;
		if (dda->side == 1 && rays->rayDirY > 0)
			text->color = 2;
		if (dda->side == 1 && rays->rayDirY < 0)
			text->color = 3;
		text->color = ((unsigned int *)text->text_array[text->color])
		[text->texX + text->texY * text->texWidth];
		img_pix_put(dda->img, dda->x, y, text->color);
		y++;
	}
	return (y);
}

int	load_textures(t_data *data, t_img *img, t_text *text)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(text->texFiles[i++], O_RDONLY);
		if (fd <= 0)
			return (1);
		close(fd);
	}
	text->textures = malloc(sizeof(void *) * 4);
	text->text_array = malloc(sizeof(void *) * 4);
	i = 0;
	while (i < 4)
	{
		text->textures[i] = mlx_xpm_file_to_image(data->mlx, text->texFiles[i],
				&text->texHeight, &text->texWidth);
		text->text_array[i] = mlx_get_data_addr(text->textures[i], 
				&img->bpp, &img->szline, &img->endian);
		i++;
	}
	// free text->textFiles d'une facon ou d'une autre !!
    return (0);
}
