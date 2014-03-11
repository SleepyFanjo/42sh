# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/01/09 16:29:41 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRC= main.c \
	 ft_error.c \
	 list.c \
	 ft_make_raw.c \
	 info_list.c \
	 info_term.c \
	 print_list.c \
	 tput_putchar.c \
	 clear_term.c \
	 print_correct.c \
	 modify_list.c \
	 return_to_shell.c \
	 get_read.c \
	 exit_clean.c

OBJ= $(SRC:.c=.o)
NAME= ft_select
DIR_LFT= ./libft
DIR_CAP= /usr/lib

all: $(NAME)

$(NAME): $(OBJ) 
	@(cd libft ; make)
	$(CC) -o $(NAME) $(OBJ) -L$(DIR_LFT) -L$(DIR_CAP) -lft -ltermcap

%.o: %.c
	$(CC) -c $(CFLAGS) $< -I./ -I$(DIR_LFT) -I$(DIR_CAP)

clean:
	@(cd libft ; make clean)
	rm -rf $(OBJ)

fclean: clean
	@(cd libft ; make fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
