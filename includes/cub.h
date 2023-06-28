/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:27:06 by achansar          #+#    #+#             */
/*   Updated: 2023/06/28 18:41:42 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "structs.h"
# include "../library/mlx/mlx.h"
# include "get_next_line.h"

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
int ft_dda(t_game *game, t_rays *rays, t_digdifanalyzer *dda);
int drawloop(t_game *game, t_digdifanalyzer *dda);
void	img_pix_put(t_img *img, int x, int y, int color);

// CONTROLS FUNCTIONS
int	ft_keys(int key, t_data *set);
int key_release(int key, t_move *move);

// MOVE FUNCTIONS
void ft_move(t_game *game, t_move *move, char **map);

// TEXTURES FUNCTIONS
int load_textures(t_data *data, t_img *img, t_text *text);
int color_floor_ceiling(t_digdifanalyzer *dda, t_text *text, int y);
int put_textures(t_digdifanalyzer *dda, t_text *text, int lineH, int *y);

// LIBFT FUNCTIONS
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

//TEST FUNCTIONS
void	print_map(int **map);
char		**ft_upscale(int size, int old_size);

//DISPLAY FUNCTIONS
int	open_window(t_data *set);
int create_img(t_data *set);

// PARSING FUNCTIONS
void	parsing(t_game *game, int ac, char **av);
void	read_map(t_game *game, char *file);
void	rgb_check(t_game *game, char *rgb, int *color);
void	errors(t_game *game, int error, char *str);
void	extension_check(t_game *game, char *av);
void	error_map(t_game *game, char *map);
void	walls_missing(t_game *game, char *map);
void	init_player_pos(t_game *game);
void	add_new_pos(t_pos *pos, double x, double y);
int		player(char c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup_pars(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
int		ft_atoi_pars(t_game *game, char *str);
int		ft_isdigit(int c);
t_pos	player_coord(char *map, int i);
int		max_vert(char **map);
int		max_hor(char **map, int i);
void	filling_sprite_tab(t_game *game);

#endif