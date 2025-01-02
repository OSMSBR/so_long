# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 20:51:30 by osebbar           #+#    #+#              #
#    Updated: 2024/10/12 20:51:30 by osebbar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
OBJ			= $(SRC:.c=.o)
SRC			= 	ft_strlcpy.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_memset.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strcmp.c \
				ft_strjoin.c \
				ft_strlen.c 

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $@ $^

%.o:		%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
