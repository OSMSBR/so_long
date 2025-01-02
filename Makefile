# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 21:33:06 by osebbar           #+#    #+#              #
#    Updated: 2024/10/14 03:05:09 by osebbar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	./mlx/libmlx_Linux.a
LFT			=	libft/libft.a
INC			=	-I ./src -I ./libft -I ./mlx
LIB			=	./libft/libft.a ./mlx/libmlx_Linux.a  -Imlx_linux -lXext -lX11 -lm -lz
OBJ			=	$(SRC:.c=.o)
SRC			=	src/die.c \
				src/draw.c \
				src/event.c \
				src/game_destroy.c \
				src/game_init.c \
				src/map_height.c \
				src/map_init.c \
				src/map_isvalid.c \
				src/map_parsing.c \
				src/map_read.c \
				src/map_width.c \
				src/mlx_utils.c \
				src/move_player.c \
				src/root_destroy.c \
				src/root_init.c \
				src/so_long.c \
				src/update.c \


all:		$(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "P L A Y ... !"

$(MLX):
			@make -s -C mlx

$(LFT):
			@make -s -C libft

src/%.o:	src/%.c
			@$(CC) $(FLAGS) $(INC) -g3 -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) src/*.o

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)

re:			fclean all
re_b:			fclean bonus

.PHONY:		all clean fclean re
