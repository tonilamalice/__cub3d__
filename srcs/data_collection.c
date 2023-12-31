/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:18 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/30 17:18:25 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i] == '1' || str[i] == '0')
		return (1);
	return (0);
}

char	*copy(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] == ' ' || src[i] == '	')
		i++;
	if (src[i] == ' ' || src[i] == '	')
		i++;
	dest = ft_strdup_pars(src + i);
	i = 0;
	while (dest[i] != '\n')
		i++;
	if (dest[i] == '\n')
		dest[i] = '\0';
	i = 0;
	return (dest);
}

void	data_collection(t_game *game, char *str)
{
	if (!str[0])
		return ;
	else if (str[0] == '1' || str[0] == '0'
		|| str[0] == ' ' || game->map[0] != '\0')
		game->map = ft_strjoin(game->map, str);
	else if (player(str[0]) && str[1] && (str[1] == '0' || str[1] == '1'))
		game->map = ft_strjoin(game->map, str);
	else if (str[0] == 'N' && str[1] && str[1] == 'O' && !game->sprite.n_path)
		game->sprite.n_path = copy(str + 2);
	else if (str[0] == 'S' && str[1] && str[1] == 'O' && !game->sprite.s_path)
		game->sprite.s_path = copy(str + 2);
	else if (str[0] == 'E' && str[1] && str[1] == 'A' && !game->sprite.e_path)
		game->sprite.e_path = copy(str + 2);
	else if (str[0] == 'W' && str[1] && str[1] == 'E' && !game->sprite.w_path)
		game->sprite.w_path = copy(str + 2);
	else if (str[0] == 'F' && !game->floor)
		game->floor = copy(str + 1);
	else if (str[0] == 'C' && !game->roof)
		game->roof = copy(str + 1);
	else if (str[0] != '\n')
		errors(game, 6, str);
}

void	read_map(t_game *game, char *file)
{
	int		i;
	int		fd;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		errors(game, 5, NULL);
	game->map = malloc(sizeof (char) * 1);
	if (!game->map)
		errors(game, 2, NULL);
	game->map[0] = '\0';
	while (game->map)
	{
		i = 0;
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		while (!is_map_line(buffer) && (buffer[i] == ' ' || buffer[i] == '	'))
			i++;
		data_collection(game, buffer + i);
		if (buffer)
			free (buffer);
	}
}
