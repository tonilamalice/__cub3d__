/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:30:01 by ade-bast          #+#    #+#             */
/*   Updated: 2023/06/27 12:24:28 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	error_arg(int error, char *str)
{
	if (error == 1)
	{
		write(2, "Error\nWrong number of arguments.\n", 34);
		exit(EXIT_FAILURE);
	}
	else if (error == 3)
	{
		write (2, "Error\nWrong file name : \n", 25);
		write (2, str, ft_strlen(str));
	}
}

void	handle_syntax_error(int error, char *str)
{	
	if (error == 10)
	{
		write(2, "Error\nRGB format is incorrect : \n", 33);
		write (2, str, ft_strlen(str));
	}
	else if (error == 6)
	{
		write(2, "Error\nSyntax error in the file : \n", 34);
		write (2, str, ft_strlen(str));
	}
	else if (error == 11)
	{	
		write(2, "Error\nThis file does not exist/is corrupted :\n", 46);
		write (2, str, ft_strlen(str));
	}
	else if (error == 14)
	{	
		write(2, "Error\nTextures do not exist\n", 29);
		exit(EXIT_FAILURE);
	}
}

void	handle_map_error(int error, char *str)
{	
	if (error == 1)
		write(2,
			"Error\nThere is too few or too many character(s).\n", 49);
	else if (error == 8)
	{
		write(2, "Error\nIncorrect character in the map : \n", 40);
		write (2, &str[0], 1);
	}
	else if (error == 9)
	{	
		write(2, "Error\nA wall of the map is open here :\n", 39);
		write (2, str, ft_strlen(str));
	}
	else if (error == 5)
		write(2, "Error\nThis map does not exist.\n", 30);
}

void	handle_parse_error(int error)
{
	if (error == 12)
		write(2, "Error\nNeed NO/SO/WE/EA and F/C color.\n", 38);
	if (error == 13)
		write(2, "Error\nTextures need xpm extension\n", 34);
}

void	errors(t_game *game, int error, char *str)
{
	(void) game;
	error_arg(error, str);
	handle_parse_error(error);
	handle_map_error(error, str);
	handle_syntax_error(error, str);
	exit(EXIT_FAILURE);
}
