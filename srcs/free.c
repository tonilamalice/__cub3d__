/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:12:40 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:04:37 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	free_texture(t_text *text)
{
	if (text->texFiles)
		free(text->texFiles);
	if (text->textures)
		free(text->textures);
	if (text->text_array)
		free(text->text_array);
	free(text);
	return (0);
}

int	free_game(t_game *game)
{
	if (game)
	{
		if (game->move)
			free(game->move);
		if (game->rays)
			free(game->rays);
		if (game->dda)
			free(game->dda);
		if (game->text)
			free_texture(game->text);
		if (game->worldMap)
			free_split(game->worldMap);
		free(game);
	}
	return (0);
}
