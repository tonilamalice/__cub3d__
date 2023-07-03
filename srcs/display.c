/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:53:32 by arnalove          #+#    #+#             */
/*   Updated: 2023/07/03 14:05:06 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	open_window(t_data *set)
{
	set->win = NULL;
	set->mlx = mlx_init();
	if (!set->mlx)
		return (1);
	set->win = mlx_new_window(set->mlx, WIDTH, HEIGHT, "cub3D");
	if (!set->win)
		return (1);
	return (0);
}

int	create_img(t_data *set)
{
	set->img.img = mlx_new_image(set->mlx, WIDTH, HEIGHT);
	if (!set->img.img)
	{
		mlx_destroy_window(set->mlx, set->win);
		return (1);
	}
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bpp,
			&set->img.szline, &set->img.endian);
	return (0);
}