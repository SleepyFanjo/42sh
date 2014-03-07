make -C ../parser_mofo
rm ../parser_mofo/main_test.o
gcc -Wall -Wextra -Werror -g autocomplete.c l_search.c l_to_check.c l_path.c l_list.c  l_tok_game.c  main_autoC.c ../parser_mofo/*.o  -I ../libft -I../parser_mofo -L ../libft -lft
