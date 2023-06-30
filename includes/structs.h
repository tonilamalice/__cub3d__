/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:44:22 by achansar          #+#    #+#             */
/*   Updated: 2023/06/30 16:53:52 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_keys {
	ESC			= 53,
	UP			= 13,
	DOWN		= 1,
	LEFT		= 0,
	RIGHT		= 2,
	TURNL		= 123,
	TURNR		= 124
};

typedef struct s_pos {
	double	x;
	double	y;
}	t_pos;

typedef struct s_sprite {
	char	*n_path;
	char	*s_path;
	char	*e_path;
	char	*w_path;
	char	**tab_path;
}	t_sprite;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		szline;
	int		endian;
}	t_img;

typedef struct s_digdifanalyser {
    double mapX;
    double mapY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    int stepX;
    int stepY;//       may be int
    int hit;
    int side;
	double perpWallDist;
	int		x;
	int start;
	int end;
	int lineH;
	t_img	*img;
}   t_digdifanalyzer;

typedef struct s_text {
	int	texWidth;
	int	texHeight;
	char **texFiles;
	char **textures;
	char **text_array;

	double wallX;
	int texX;
	int texY;
	int color;

	int color_floor;
	int color_ceiling;
}	t_text;

typedef struct s_move {
	double moveSpeed;
	double rotSpeed;
	bool forward;
	bool back;
	bool turn;
	bool left;
	bool right;
	bool firstscreen;
}	t_move;

typedef struct s_rays {
    double cameraX;
    double rayPosX;
    double rayPosY;
    double rayDirX;
    double rayDirY;
}   t_rays;

typedef struct s_game {
	char		*floor;
	char		*roof;
	char		*map;
	char		player_dir;
	
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		color_floor;
	int		color_roof;
	char		**worldMap;
	t_move	*move;
    t_rays  *rays;
	t_digdifanalyzer	*dda;
	t_text				*text;

	t_sprite	sprite;
	t_pos		player;
}	t_game;

typedef struct s_data {//          malloc
	void		*mlx;
	void		*win;
	t_img		img;
	t_game		*game;
}	t_data;
