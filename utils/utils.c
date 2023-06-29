/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:48 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/29 14:41:28 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub.h"

void	add_new_pos(t_pos *pos, double x, double y)
{
	pos->x += x;
	pos->y += y;
}

int	player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
void	extension_and_file_check(t_game *game, char *xpm)
{
	int	len;
	int	fd;

	fd = open(xpm, O_RDONLY);
	if (fd == -1)
		errors(game, 14, NULL);
	len = ft_strlen(xpm);
	if (xpm[len - 1] == 'm' && xpm[len - 2] == 'p'
		&& xpm[len - 3] == 'x' && xpm[len - 4] == '.')
		;
	else
		errors(game, 13, xpm);
	
}
	
void	filling_sprite_tab(t_game *game)
{
	int	i;
	int	len;

	len = ft_strlen(game->sprite.n_path) + ft_strlen(game->sprite.s_path) + 
			ft_strlen(game->sprite.w_path) + ft_strlen(game->sprite.e_path);
	extension_and_file_check(game,game->sprite.n_path);
	extension_and_file_check(game,game->sprite.s_path);
	extension_and_file_check(game,game->sprite.w_path);
	extension_and_file_check(game,game->sprite.e_path);
	i = 0;
	game->sprite.tab_path = malloc(sizeof(char *) * len + 1);
	if(!game->sprite.tab_path)
		exit(EXIT_FAILURE);
	game->sprite.tab_path[0] = game->sprite.n_path;
	game->sprite.tab_path[1] = game->sprite.s_path;
	game->sprite.tab_path[2] = game->sprite.e_path;
	game->sprite.tab_path[3] = game->sprite.w_path;
}