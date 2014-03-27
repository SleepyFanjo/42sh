/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lredoban <lredoban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:32:37 by lredoban          #+#    #+#             */
/*   Updated: 2014/03/27 10:17:21 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int			is_opt(char *s)
{
	int				i;

	i = 1;
	while (s[i] != '\0' && (s[i] == 'n' || s[i] == 'e' || s[i] == 'E'))
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

static int			*echo_init_opt(void)
{
	int				*opt;

	if (!(opt = (int *)malloc(sizeof(int) * 3)))
		exit(0);
	opt[0] = 1;
	opt[1] = 0;
	opt[2] = 0;
	return (opt);
}

int					*check_opt(char **arg)
{
	int				i;
	int				opt_e;
	int				*opt;

	i = 1;
	opt = echo_init_opt();
	opt_e = 1;
	while (arg[i] != NULL && arg[i][0] == '-')
	{
		if (is_opt(arg[i]) == 1)
		{
			if (ft_strchr(arg[i], 'n') != NULL)
				opt[1]++;
			if (ft_strchr(arg[i], 'e') != NULL)
				opt_e = 0;
			if (ft_strchr(arg[i], 'E') != NULL)
				opt[2] = (opt[2] + 1) * opt_e;
			opt[0] = ++i;
		}
		else
			return (opt);
	}
	return (opt);
}
