/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:10:30 by achansar          #+#    #+#             */
/*   Updated: 2023/06/29 14:23:46 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int color_floor_ceiling(t_digdifanalyzer *dda, t_text *text, int y)
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

// NO = 0 | SO = 1 | EA = 2 | WE = 3

int put_textures(t_digdifanalyzer *dda, t_rays *rays, t_text *text, int *y)
{
	*y = dda->start;
	while (*y < dda->end)
	{
		text->texY = (int)(*y * 2 - HEIGHT + dda->lineH) * (text->texHeight / 2) / dda->lineH;
		text->color = 1;
        if (dda->side == 0 && rays->rayDirX > 0)
            text->color = 0;
        if (dda->side == 1 && rays->rayDirY < 0)
            text->color = 1;
		text->color = ((unsigned int *)text->text_array[text->color])[text->texX + text->texY * text->texWidth];//     -> ici pour ajouter un index
		img_pix_put(dda->img, dda->x, *y, text->color);
		*y += 1;
	}
	return (0);
}

int load_textures(t_data *data, t_img *img, t_text *text)
{
	int i;
    int fd;

	i = 0;
	while (i < 4)
	{
		fd = open(text->texFiles[i++], O_RDONLY);
		if (fd <= 0)
			return (1);
		close(fd);
	}
	text->textures = malloc(sizeof(void *) * 4);// protection
    text->text_array = malloc(sizeof(void *) * 4);// protection        double malloc, double mlx()
	i = 0;
	while (i < 4)
	{
		// printf("test pour texture numero [%d] = %s\n", i, text->texFiles[i]);
    	text->textures[i] = mlx_xpm_file_to_image(data->mlx, text->texFiles[i], &text->texHeight, &text->texWidth);
    	text->text_array[i] = mlx_get_data_addr(text->textures[i], &img->bpp, &img->szline, &img->endian);
		// printf("color exemple = %d\n", text->text_array[0][40]);
		i++;
	}
	// free text->textFiles d'une facon ou d'une autre !!
    return (0);
}
