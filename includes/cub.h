/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:27:06 by achansar          #+#    #+#             */
/*   Updated: 2023/06/26 15:56:32 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "../library/mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "structs.h"

// # define WHITE 0xFFFFFF
# define RED 0xFF0000
# define WIDTH 800
# define HEIGHT 400
# define UPSCALE 42



// MAIN FUNCTIONS
int	destroy(t_data *set);
t_data *init_data(void);
int render(t_data *data, t_game *game, t_move *move, t_rays *rays);
int call_to_render(t_data *data);

// DRAW FUNCTIONS
int drawloop(t_digdifanalyzer *dda, int x);

// CONTROLS FUNCTIONS
int	ft_keys(int key, t_data *set);
int key_release(int key, t_move *move);

// MOVE FUNCTIONS
void ft_move(t_game *game, t_move *move, int **map);

// LIBFT FUNCTIONS
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

//TEST FUNCTIONS
void	print_map(int **map);
int		**ft_upscale(int size, int old_size);

//DISPLAY FUNCTIONS
int	open_window(t_data *set);

#endif