/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:26:57 by achansar          #+#    #+#             */
/*   Updated: 2023/06/29 17:31:22 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
feedback loop ?
map is mirroring
free_all()
norm
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

	data = init_data(argc, argv);
	// int i = 0;
	// while (data->game->worldMap[i])
	// 	printf("%s\n", data->game->worldMap[i++]);
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
