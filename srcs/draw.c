/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:10:43 by achansar          #+#    #+#             */
/*   Updated: 2023/05/19 15:37:29 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

// static void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;

// 	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
// 	{
// 		pixel = img->addr + (img->szline * y + x * (img->bpp / 8));
// 		*(int *)pixel = color;
// 	}
// }

// // function to call img_pix_put for each int of a 2d array
// void	draw_map(t_data *set)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
// 	while (y < 24 * UPSCALE)
// 	{
// 		x = 0;
// 		while (x < 24 * UPSCALE)
// 		{
// 			// printf("map[%d][%d] = %d\n", y, x, map[y][x]);
// 			if (set->worldMap[y][x] >= 1)
// 				img_pix_put(&set->img, x, y, 0xFFFFFF);
// 			else if (set->worldMap[y][x] == -2)
// 				img_pix_put(&set->img, x, y, RED);
// 			else
// 				img_pix_put(&set->img, x, y, 0x000000);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);
// }
