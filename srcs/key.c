/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:08:55 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:05:06 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static void	key_press(int key, t_move *move)
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
		move->rotspeed = -0.05;
	}
	if (key == TURNR)
	{
		move->turn = true;
		move->rotspeed = 0.05;
	}
}

int	key_release(int key, t_move *move)
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
	if (key == UP || key == DOWN || key == LEFT
		|| key == RIGHT || key == TURNL || key == TURNR)
		key_press(key, data->game->move);
	else if (key == ESC)
		destroy(data);
	return (0);
}
