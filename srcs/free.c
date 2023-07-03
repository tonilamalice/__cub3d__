/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:12:40 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:01:45 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	free_texture(t_text *text)
{
	if (text->t_files)
		free(text->t_files);
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
		if (game->world_map)
			free_split(game->world_map);
		free(game);
	}
	return (0);
}
