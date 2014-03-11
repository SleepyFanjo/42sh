# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/01/29 17:58:10 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRC= main.c \
	 get_path.c \
	 parse_cmd.c \
	 get_cmd.c \
	 get_fd.c \
	 list.c \
	 launch_fork.c \
	 get_cmd_input.c \
	 find_builtin.c \
	 move_dir.c \
	 ft_exit.c \
	 get_double_quote.c \
	 fucking_env.c \
	 modify_env.c \
	 add_in_env.c \
	 delete_in_env.c \
	 get_signal.c \
	 history.c \
	 get_input.c \
	 make_raw.c \
	 apply_entry.c \
	 print_input.c \
	 tput_putchar.c \
	 apply_ctrl.c \
	 get_history.c \
	 move_cursor.c \
	 delete_letter.c

OBJ= $(SRC:.c=.o)
NAME= ft_minishell3
DIR_LFT= ./libft
DIR_TRM= /usr/lib

all: $(NAME)

$(NAME): $(OBJ) 
	@(cd libft ; make)
	$(CC) -o $(NAME) $(OBJ) -L$(DIR_LFT) -L$(DIR_TRM) -lft -ltermcap

%.o: %.c
	$(CC) -c $(CFLAGS) $< -I./ -I./libft

clean:
	@(cd libft ; make clean)
	rm -rf $(OBJ)

fclean: clean
	@(cd libft ; make fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
