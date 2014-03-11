#include "select_cmd.h"

int					main(void)
{
	char			*str;

while(42)
{
	ft_putstr("(.)(.) > ");
	str = select_cmd(9);
	write(1, "\n", 1);
	ft_putstr("(.)(.) > ");
	ft_putendl(str);
	if (!ft_strcmp(str, "exit"))
		break ;
}
	return (0);
}
