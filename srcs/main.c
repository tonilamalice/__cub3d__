/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:26:57 by achansar          #+#    #+#             */
/*   Updated: 2023/06/29 10:54:13 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
gerer textures orientation
gerer deplacement dans murs
get pos initial + orientation 
translate (r, g, b) to hexa
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