/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:26:57 by achansar          #+#    #+#             */
/*   Updated: 2023/06/28 16:46:08 by ade-bast         ###   ########.fr       */
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
	// t_game	game;

	// ft_memset(&game, 0, sizeof (t_game));
	// parsing(&game, argc, argv);

    (void)argc;
    (void)argv;

	data = init_data();
	// print_map(data->game->worldMap);
	// draw_map(set);
	// ft_memset(data->game, 0, sizeof (t_game));
	// parsing(data->game, argc, argv);
	
	load_textures(data, &data->img, data->game->text);
	create_img(data);
	render(data, data->game, data->game->move, data->game->rays);
	mlx_hook(data->win, 2, (1L << 0), &ft_keys, data);
	mlx_hook(data->win, 3, (1L << 1), &key_release, data->game->move);
	mlx_hook(data->win, 17, 0, &destroy, &data);
	mlx_loop_hook(data->mlx, &call_to_render, data);//                                loop is here
    mlx_loop(data->mlx);
    return (0);
}