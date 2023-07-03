/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:26:57 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 12:43:30 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	destroy(t_data *data)
{
	free_game(data->game);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = init_data(argc, argv);
	if (!data)
		return (1);
	load_textures(data, &data->img, data->game->text);
	if (create_img(data))
		destroy(data);
	mlx_hook(data->win, 2, (1L << 0), &ft_keys, data);
	mlx_hook(data->win, 3, (1L << 1), &key_release, data->game->move);
	mlx_hook(data->win, 17, 0, &destroy, data);
	mlx_loop_hook(data->mlx, &call_to_render, data);
	mlx_loop(data->mlx);
	return (0);
}
