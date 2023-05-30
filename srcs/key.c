/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:08:55 by achansar          #+#    #+#             */
/*   Updated: 2023/05/30 17:21:17 by arnalove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int	ft_arrows(t_data *set, int key)
{
	// int	i;
	// int	j;

	// i = 0;
	(void)key;
	(void)set;
	printf("In arrows\n");
	// while (i < 24 * UPSCALE)
	// {
	// 	j = 0;
	// 	while (j < 24 * UPSCALE)
	// 	{
	// 		// if (set->worldMap[i][j] == -2)
	// 		// {
	// 		// 	if (key == UP && set->worldMap[i - 1][j] == 0)
	// 		// 	{
	// 		// 		set->worldMap[i - 1][j] == -2;
	// 		// 		set->worldMap[i][j] == 0;
	// 		// 	}
	// 		// }
	// 		j++;
	// 	}
	// 	i++;
	// }
	// draw_map(set);
	// print_map(set->worldMap);
	return (0);
}

static void key_press(int key, t_move *move)
{
	if (key == UP)
		move->forward = true;
	if (key == DOWN)
		move->back = true;
	if (key == LEFT)
		move->left = true;
	if (key == RIGHT)
		move->right = true;
	if (key == TURNL)
	{
		move->turn = true;
		move->rotSpeed = 0.2;
	}
	if (key == TURNR)
	{
		move->turn = true;
		move->rotSpeed = -0.2;
	}
	// printf("key_press done\n");
}

int key_release(int key, t_move *move)
{
	if (key == UP)
		move->forward = false;
	if (key == DOWN)
		move->back = false;
	if (key == LEFT)
		move->left = false;
	if (key == RIGHT)
		move->right = false;
	if (key == TURNL)
		move->turn = false;
	if (key == TURNR)
		move->turn = false;
	return (0);
}

int	ft_keys(int key, t_data *data)
{
	// if (key && key != ESC)
	// 	printf("%d\n", key);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		key_press(key, data->game->move);
		// printf("forward = %d\n", data->game->move->forward);
	}
	else if (key == ESC)
		destroy(data);
	return (0);
}
