/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:44:22 by achansar          #+#    #+#             */
/*   Updated: 2023/06/28 15:26:54 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_keys {
	ESC			= 53,
	UP			= 13,
	DOWN		= 1,
	LEFT		= 12,
	RIGHT		= 2,
	TURNL		= 123,
	TURNR		= 124
};

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
	t_img	*img;
}   t_digdifanalyzer;

typedef struct s_text {
	int	texWidth;
	int	texHeight;
	char *texFiles;
	char *textures;
	char *text_array;

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
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		screenWidth;
	int		screenHeight;
	int		**worldMap;
	t_move	*move;
    t_rays  *rays;
	t_digdifanalyzer	*dda;
	t_text				*text;
}	t_game;

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_img		img;
	t_game		*game;
}	t_data;
