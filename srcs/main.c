/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:26:57 by achansar          #+#    #+#             */
/*   Updated: 2023/05/19 16:31:41 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
1 Set minilibX
2 set a 2D world
3 build the DDA algo and make it visible
4 add moves and rotation with the transfo matrix
5 build the perpWallDist algo
6 draw lines (blocks)
7 add floor and ceiling
8 add textures
*/

int	destroy(t_data *data)
{
	// free game;
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int main(int argc, char **argv)
{
    t_data  *data = NULL;

    (void)argc;
    (void)argv;

	data = init_data();
	// print_map(worldMap);
	// draw_map(set);

	mlx_hook(data->win, 2, (1L << 0), &ft_keys, &data);
	mlx_hook(data->win, 3, (1L << 1), &key_release, &data);
	mlx_hook(data->win, 17, 0, &destroy, &data);
	// mlx_loop_hoo(&render);
    mlx_loop(data->mlx);
    return (0);
}
