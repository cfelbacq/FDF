# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 15:46:16 by cfelbacq          #+#    #+#              #
#    Updated: 2016/02/17 14:36:02 by cfelbacq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCE =	main.c \
			draw.c \
			count.c \
			fill_tab.c \
			free_tab.c \
			iso.c \
			get_next_line/get_next_line.c \
			check.c

OBJ =		main.o \
			draw.o \
			count.o \
			fill_tab.o \
			free_tab.o \
			iso.o \
			get_next_line.o \
			check.o

LIB = libft/libft.a

MLX = -L/usr/local/lib/ -I/usr/local/include -lmlx \
	  -framework OpenGl -framework Appkit

all : $(NAME)

$(NAME) :
	make re -C libft
	gcc -c -Wall -Werror -Wextra  $(SOURCE)
	gcc -g -o  $(NAME) $(OBJ) $(LIB) $(MLX)

clean :
	rm -rf $(OBJ)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all
