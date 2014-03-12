# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/19 16:24:28 by jrenouf-          #+#    #+#              #
#    Updated: 2014/03/12 17:28:26 by jrenouf-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =mult_line

CC =gcc -g

CFLAGS =-Wall -Wextra -Werror

LIB =../libft

LIBCAPS =/usr/lib

SRC = main.c \
	  edit_line.c \
	  move.c \
	  refresh.c \
	  select_cmd.c \
	  term.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		(make -C $(LIB))
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB) -lft -L$(LIBCAPS) -ltermcap


%.o: %.c select_cmd.h
		$(CC) $(CFLAGS) -I $(LIB)includes/ -c $<

clean:
		(make -C $(LIB) $@)
		rm -f $(OBJ)

fclean: clean
		(make -C $(LIB) $@)
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
.SILENT:
