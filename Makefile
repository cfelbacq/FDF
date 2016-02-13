# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 15:46:16 by cfelbacq          #+#    #+#              #
#    Updated: 2016/02/13 15:27:49 by cfelbacq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCE =	main.c \
			draw.c \
			count.c \
			fill_tab.c \
			free_tab.c \
			iso.c

OBJ =		main.o \
			draw.o \
			count.o \
			fill_tab.o \
			free_tab.o \
			iso.o
all : $(NAME)

$(NAME) :
	gcc -c  $(SOURCE)
	gcc -o $(NAME) $(OBJ) get_next_line.o ../libft/libft.a -L/usr/local/lib/ -I/usr/local/include -lmlx \
		-framework OpenGl -framework Appkit

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
