/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:27 by achansar          #+#    #+#             */
/*   Updated: 2023/05/19 16:53:43 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	open_window(t_data *set)
{
	set->mlx = mlx_init();
	if (!set->mlx)
		return (1);
	set->win = mlx_new_window(set->mlx, WIDTH, HEIGHT, "cub3D");
	if (!set->win)
		return (1);
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

static t_rays *init_rays(void)
{
	t_rays *rays;

	rays = NULL;
	rays = malloc(sizeof(t_rays));
	return (rays);
}

static t_move *init_move(void)
{
	t_move *move;
	
	move = NULL;
	move = malloc(sizeof(t_move));// protection
	move->moveSpeed = 0.2;
	move->rotSpeed = 0.2;
	move->forward = false;
	move->back = false;
	move->left = false;
	move->right = false;
	move->turn = false;
	move->firstscreen = true;
	return (move);
}

static t_game	*init_game(void)
{
	t_game *game;

	game = NULL;
	game = malloc(sizeof(t_game));// protection
	game->posX = 22.0;
	game->posY = 11.5;
	game->dirX = -1.0;
	game->dirY = 0.0;
	game->planeX = 0.0;
	game->planeY = -1.0;
	game->screenWidth = 480;
	game->screenHeight = 240;
	game->worldMap = ft_upscale(24, UPSCALE);
	game->move = init_move();
	game->rays = init_rays();
	return (game);
}

t_data *init_data(void)
{
	t_data *data;

	data = NULL;
	data = malloc(sizeof(t_data));
	open_window(data);// .             protection
	data->game = init_game();
	return (data);
}