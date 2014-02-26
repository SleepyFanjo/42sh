make -C ../libft
gcc -Wall -Wextra -Werror *.c -L ../libft -lft -L /usr/lib -ltermcap