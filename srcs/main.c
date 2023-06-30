/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:26:57 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 15:23:02 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

/*
feedback loop ?
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

int	main(int argc, char **argv)
{
    t_data 	*data = NULL;

	data = init_data(argc, argv);
	load_textures(data, &data->img, data->game->text);
	create_img(data);
	mlx_hook(data->win, 2, (1L << 0), &ft_keys, data);
	mlx_hook(data->win, 3, (1L << 1), &key_release, data->game->move);
	mlx_hook(data->win, 17, 0, &destroy, data);
	mlx_loop_hook(data->mlx, &call_to_render, data);
	mlx_loop(data->mlx);
	return (0);
}
