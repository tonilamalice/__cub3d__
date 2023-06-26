/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:10:43 by achansar          #+#    #+#             */
/*   Updated: 2023/06/26 16:48:05 by achansar         ###   ########.fr       */
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

static int draw_column(int x, int start, int end, t_digdifanalyzer *dda)
{
    int y;

    y = start;
    while (y < end)
    {
        if (dda->side == 1)
            img_pix_put(dda->img, x, y, 0xCCCCCC);
        else
            img_pix_put(dda->img, x, y, 0xf2f2f2);
        y++;
    }
    if (end < 0)
        end = HEIGHT;
    y = end;
    while (y < HEIGHT)
    {
        img_pix_put(dda->img, x, y, 0xcc0000);
        img_pix_put(dda->img, x, HEIGHT-y-1, 0x006666);
        y++;
    }
    return (0);
}

int drawloop(t_digdifanalyzer *dda, int x)
{
    int lineH;
    int start;
    int end;

    lineH = abs((int)((double)HEIGHT / dda->perpWallDist));
    start = -lineH / 2 + (double)HEIGHT / 2;
    end = lineH / 2 + (double)HEIGHT / 2;

    if (start < 0)
        start = 0;
    if (end >= HEIGHT)
        end = HEIGHT - 1;

    // printf("before draw_column\n");
    draw_column(x, start, end, dda);
    return (0);
}
