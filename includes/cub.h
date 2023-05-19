/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:27:06 by achansar          #+#    #+#             */
/*   Updated: 2023/05/19 16:44:56 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "structs.h"

// # define WHITE 0xFFFFFF
# define RED 0xFF0000
# define WIDTH 480
# define HEIGHT 240
# define UPSCALE 42



// MAIN FUNCTIONS
int	destroy(t_data *set);
t_data *init_data(void);


// DRAW FUNCTIONS
void	draw_map(t_data *set);

// CONTROLS FUNCTIONS
int	ft_keys(int key, t_data *set);
void key_release(int key, t_move *move);

// LIBFT FUNCTIONS
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

//TEST FUNCTIONS
void	print_map(int **map);
int		**ft_upscale(int size, int old_size);

#endif