/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:53:38 by achansar          #+#    #+#             */
/*   Updated: 2023/06/28 17:29:24 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int render(t_data *data, t_game *game, t_move *move, t_rays *rays)
{
    game->dda->x = 0;
    if (move->forward || move->back || move->left || move->right || move->turn || move->firstscreen)
    {
        move->firstscreen = false;
        ft_move(game, move, game->worldMap);
        ft_bzero(data->img.addr, WIDTH * HEIGHT * sizeof(int));
        while (game->dda->x <= game->screenWidth)
        {
            ft_dda(game, rays, game->dda);
            drawloop(game, game->dda);
            game->dda->x++;
        }
        mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    }
    return (0);
}

int call_to_render(t_data *data)
{
    render(data, data->game, data->game->move, data->game->rays);
    return (0);
}
