#include "select_cmd.h"

int					main(void)
{
	char			*str;

	ft_putstr("(.)(.) > ");
	str = select_cmd(9);
	write(1, "\n", 1);
	ft_putstr("(.)(.) > ");
	ft_putendl(str);
	return (0);
}
