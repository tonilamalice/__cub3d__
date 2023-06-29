# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 10:47:25 by achansar          #+#    #+#              #
#    Updated: 2023/06/29 13:36:41 by ade-bast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = cub3D

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wno-unused -Wno-unused-parameter -Wextra -O1 -O2 -O3 
SEG = -fsanitize=address -g
# MLX = -lmlx -framework OpenGL -framework AppKit

#CUB3D FILES
SRC_PATH = ./srcs/
SRC =	main \
		init \
		map \
		render \
		raycasting \
		draw \
		key \
		move \
		display \
		textures \
		errors_management \
		parsing \
		data_collection \
		player_pos_and_color \
		map_check \
		walls_check

C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRC:=.o))

SRC_PATH_UTILS = ./utils/
SRC_UTILS =	player_coord \
			utils \
			libft \
			ft_atoi \
			ft_split \
			gnl/get_next_line \
			gnl/get_next_line_utils
UTILS_FILES = $(addprefix $(SRC_PATH_UTILS), $(SRC_UTILS:=.c))
UTILS_OBJ = $(addprefix $(SRC_PATH_UTILS), $(SRC_UTILS:=.o))

#LIBFT
LBFT_PATH = ./libft/
LBFT =		ft_bzero \
			ft_memset \
			ft_strlen \
			ft_strdup
LBFT_FILES = $(addprefix $(LBFT_PATH), $(LBFT:=.c))
LBFT_OBJ = $(addprefix $(LBFT_PATH), $(LBFT:=.o))

# MLX
MLX_PATH = library/mlx
MLX_LIB	= ${MLX_PATH}/libmlx.a ${MLX_FLAGS}
MLX_INC = -I ${MLX_PATH}/
MLX_FLAGS = -framework OpenGL -framework AppKit

#RULES
all: $(NAME)

$(NAME): $(OBJ) $(LBFT_OBJ) $(UTILS_OBJ)
	@make -sC $(MLX_PATH)
	@ $(CC) $(FLAGS) $(SEG) $(OBJ) $(LBFT_OBJ) $(UTILS_OBJ) $(MLX_LIB) -o $(NAME)

.c.o:
	@ $(CC) $(FLAGS) $(SEG) $(MLX_INC) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LBFT_OBJ) $(UTILS_OBJ)
	@make clean -sC $(MLX_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	

.PHONY: all clean fclean re