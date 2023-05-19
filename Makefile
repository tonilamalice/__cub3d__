# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 10:47:25 by achansar          #+#    #+#              #
#    Updated: 2023/05/17 16:15:51 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = cub3D

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wno-unused -Wno-unused-parameter -Wextra -O1 -O2 -O3 
SEG = -fsanitize=address -g
MLX = -lmlx -framework OpenGL -framework AppKit 

#CUB3D FILES
SRC_PATH = ./srcs/
SRC =	main \
		map \
		draw \
		key
C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRC:=.o))

#LIBFT
LBFT_PATH = ./libft/
LBFT =		ft_bzero \
			ft_memset
LBFT_FILES = $(addprefix $(LBFT_PATH), $(LBFT:=.c))
LBFT_OBJ = $(addprefix $(LBFT_PATH), $(LBFT:=.o))

#RULES
all: $(NAME)

$(NAME): $(OBJ) $(LBFT_OBJ)
	@ $(CC) $(FLAGS) $(SEG) $(OBJ) $(LBFT_OBJ) $(MLX) -o $(NAME)

.c.o:
	@ $(CC) $(FLAGS) $(SEG) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re