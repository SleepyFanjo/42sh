# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/18 11:31:57 by lredoban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
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
	 parser_mofo/q_subshell.c \
	 parser_mofo/q_shell_cmd.c \
	 src_select_cmd/edit_line.c \
	 src_select_cmd/move.c \
	 src_select_cmd/refresh.c \
	 src_select_cmd/term.c \
	 src_select_cmd/select_cmd.c \
	 src_select_cmd/j_malloc.c \
	 src_select_cmd/autocomplete.c \
	 src_select_cmd/l_list.c \
	 src_select_cmd/l_path.c \
	 src_select_cmd/l_search.c \
	 src_select_cmd/l_to_check.c \
	 src_select_cmd/l_tok_game.c \
	 src_select_cmd/l_edit_word.c \
	 src_select_cmd/select_history.c \
	 signal/init_sig.c \
	 signal/quit_term.c \
	 signal/kill_cmd.c \
	 builtin/add_in_env.c \
	 builtin/modify_env.c \
	 builtin/fucking_env.c \
	 builtin/setenv.c \
	 builtin/print_env.c \
	 builtin/delete_in_env.c \
	 builtin/my_unsetenv.c \
	 builtin/ft_exit.c \
	 builtin/ft_echo.c \
	 builtin/echo_opt.c \
	 builtin/find_builtin.c \
	 builtin/move_dir.c \
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
	 kernel/add_in_history.c \
	 kernel/main.c

INCLUDES=-I includes/
INC=includes/history.h \
	includes/launch_cmd.h \
	includes/parser.h \
	includes/select_cmd.h \
	includes/struct.h \
	includes/autocomplete.h

OBJ= $(SRC:.c=.o)
NAME= 42sh
LIB=-L/usr/lib -ltermcap -L./libft -lft
DIR_LFT= libft

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ)
	@(cd $(DIR_LFT) ; make)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME) \033[0mDONE!"

%.o: %.c $(INC)
	@echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
	@$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $< -I./ -I$(DIR_LFT)

clean:
	@echo "\t\xF0\x9F\x92\xA3   Cleaning"
	@(cd $(DIR_LFT) ; make clean)
	@rm -rf $(OBJ)

fclean: clean
	@echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	@(cd $(DIR_LFT) ; make fclean)
	@rm -rf $(NAME)

re: fclean all
