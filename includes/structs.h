/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:52:57 by achansar          #+#    #+#             */
/*   Updated: 2023/07/03 13:07:39 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pos {
	double				x;
	double				y;
}	t_pos;

typedef struct s_sprite {
	char				*n_path;
	char				*s_path;
	char				*e_path;
	char				*w_path;
	char				**tab_path;
}	t_sprite;

typedef struct s_img {
	void				*img;
	char				*addr;
	int					bpp;
	int					szline;
	int					endian;
}	t_img;

typedef struct s_digdifanalyser {
	double				map_x;
	double				map_y;
	double				sidedist_x;
	double				sidedist_y;
	double				deltadist_x;
	double				deltadist_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	double				wall_dist;
	int					x;
	int					start;
	int					end;
	int					line_h;
	t_img				*img;
}	t_digdifanalyzer;

typedef struct s_text {
	int					t_width;
	int					t_height;
	char				**t_files;
	char				**textures;
	char				**text_array;

	double				wall_x;
	int					tex_x;
	int					tex_y;
	int					color;

	int					color_floor;
	int					color_ceiling;
}	t_text;

typedef struct s_move {
	double				movespeed;
	double				rotspeed;
	bool				forward;
	bool				back;
	bool				turn;
	bool				left;
	bool				right;
	bool				firstscreen;
}	t_move;

typedef struct s_rays {
	double				cam_x;
	double				raypos_x;
	double				raypos_y;
	double				raydir_x;
	double				raydir_y;
}	t_rays;

typedef struct s_game {
	char				*floor;
	char				*roof;
	char				*map;
	char				player_dir;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	int					color_floor;
	int					color_roof;
	char				**world_map;
	t_move				*move;
	t_rays				*rays;
	t_digdifanalyzer	*dda;
	t_text				*text;
	t_sprite			sprite;
	t_pos				player;
}	t_game;

typedef struct s_data {
	void				*mlx;
	void				*win;
	t_img				img;
	t_game				*game;
}	t_data;

enum e_keys {
	ESC			= 53,
	UP			= 13,
	DOWN		= 1,
	LEFT		= 0,
	RIGHT		= 2,
	TURNL		= 123,
	TURNR		= 124
};

#endif
