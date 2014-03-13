#include "../includes/select_cmd.h"

int					main(void)
{
	char			*str;

	str = select_cmd(22, "(.)(.)forever(.)(.) > ");
	write(1, "\n", 1);
	ft_putstr("(.)(.)forever(.)(.) > ");
	ft_putendl(str);
	return (0);
}
