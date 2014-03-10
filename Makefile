# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/10 16:16:46 by vwatrelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang
CFLAGS= -Wall -Werror -Wextra -g
SRC= parser_mofo/q_count_token_len.c \
	 parser_mofo/q_lexer.c \
	 parser_mofo/q_token.c \
	 parser_mofo/q_free_list.c \
	 parser_mofo/q_utility_token.c \
	 parser_mofo/q_rolex.c \
	 parser_mofo/q_inhib.c \
	 parser_mofo/q_parser.c \
	 parser_mofo/q_free_cmd.c \
	 parser_mofo/q_cmd.c \
	 parser_mofo/q_check_cmd.c \
	 parser_mofo/q_add.c \
	 parser_mofo/tmp_prompt.c \
	 src_select_cmd/edit_line.c \
	 src_select_cmd/move.c \
	 src_select_cmd/refresh.c \
	 src_select_cmd/term.c \
	 src_select_cmd/select_cmd.c \
	 builtin/add_in_env.c \
	 builtin/modify_env.c \
	 builtin/setenv.c \
	 builtin/print_env.c \
	 kernel/dup_cmd.c \
	 kernel/exec_cmd.c \
	 kernel/get_double_fd_out.c \
	 kernel/get_file_in.c \
	 kernel/get_path.c \
	 kernel/get_simple_fd_out.c \
	 kernel/get_word_in.c \
	 kernel/launch_cmd.c \
	 kernel/launch_fork.c \
	 kernel/launch_one_cmd.c \
	 kernel/exec_builtin.c \
	 kernel/main.c

INCLUDES=-I includes/
OBJ= $(SRC:.c=.o)
NAME= test
LIB=-L/usr/lib -ltermcap -L./libft -lft
DIR_LFT= libft

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< -I./ -I$(DIR_LFT)

clean:
	@(cd $(DIR_LFT) ; make clean)
	rm -rf $(OBJ)

fclean: clean
	@(cd $(DIR_LFT) ; make fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all