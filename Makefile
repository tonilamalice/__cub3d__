# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 10:47:25 by achansar          #+#    #+#              #
#    Updated: 2023/06/26 17:27:50 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = cub3D

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wno-unused -Wno-unused-parameter -Wextra -O1 -O2 -O3 
SEG = -fsanitize=address -g

#CUB3D FILES
SRC_PATH = ./srcs/
SRC =	main \
		init \
		map \
		render \
		draw \
		key \
		move \
		display
C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRC:=.o))

#LIBFT
LBFT_PATH = ./libft/
LBFT =		ft_bzero \
			ft_memset
LBFT_FILES = $(addprefix $(LBFT_PATH), $(LBFT:=.c))
LBFT_OBJ = $(addprefix $(LBFT_PATH), $(LBFT:=.o))

# MLX
MLX_PATH = library/mlx
MLX_LIB	= ${MLX_PATH}/libmlx.a ${MLX_FLAGS}
MLX_INC = -I ${MLX_PATH}/
MLX_FLAGS = -framework OpenGL -framework AppKit

#RULES
all: $(NAME)

$(NAME): $(OBJ) $(LBFT_OBJ)
	@make -sC $(MLX_PATH)
	@ $(CC) $(FLAGS) $(SEG) $(OBJ) $(LBFT_OBJ) $(MLX_LIB) -o $(NAME)

.c.o:
	@ $(CC) $(FLAGS) $(SEG) $(MLX_INC) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LBFT_OBJ)
	@make clean -sC $(MLX_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
	

.PHONY: all clean fclean re