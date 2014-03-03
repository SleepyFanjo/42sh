make -C ../parser_mofo
rm ../parser_mofo/main_test.o
gcc -Wall -Wextra -Werror autocomplete.c  main_autoC.c ../parser_mofo/*.o  -I ../libft -I../parser_mofo -L ../libft -lft
