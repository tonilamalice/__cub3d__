/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:10:43 by achansar          #+#    #+#             */
/*   Updated: 2023/05/24 16:42:39 by arnalove         ###   ########.fr       */
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
        // printf("if y < end\n");
        if (dda->side == 1)
            img_pix_put(dda->img, x, y, 0xCCCCCC);
        else
            img_pix_put(dda->img, x, y, 0xf2f2f2);
        y++;
    }
    return (0);
}

int drawloop(t_digdifanalyzer *dda, int x)
{
    int lineH;
    int start;
    int end;

    lineH = fabs((int)HEIGHT / dda->perpWallDist);
    start = (int)(-lineH / 2 + HEIGHT / 2);
    end = (int)(lineH / 2 + HEIGHT / 2);

    if (start < 0)
        start = 0;
    if (end >= HEIGHT)
        end = HEIGHT - 1;

    // printf("before draw_column\n");
    draw_column(x, start, end, dda);
    return (0);
}
