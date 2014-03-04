# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/03 12:33:25 by qchevrin          #+#    #+#              #
#    Updated: 2014/03/04 11:24:35 by qchevrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRC= main_test.c \
	 q_count_token_len.c \
	 q_lexer.c \
	 q_token.c \
	 q_free_list.c \
	 q_utility_token.c \
	 q_rolex.c \
	 q_inhib.c \
	 tmp_prompt.c

OBJ= $(SRC:.c=.o)
NAME= test
DIR_LFT= ../libft

all: $(NAME)

$(NAME): $(OBJ) 
	@(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME) $(OBJ) -L$(DIR_LFT) -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $< -I./ -I$(DIR_LFT)

clean:
	@(cd $(DIR_LFT) ; make clean)
	rm -rf $(OBJ)

fclean: clean
	@(cd $(DIR_LFT) ; make fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
