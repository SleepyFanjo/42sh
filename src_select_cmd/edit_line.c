/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:50:36 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/25 15:57:31 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_cmd.h"

void					write_str(t_param *param, char *str)
{
	int					i;

	i = 0;
	ft_putstr("(.)(.) > ");
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	(void)param;
}

void					refresh_screen(t_param *param, int mode)
{
	int					tmp;
	int					tmp2;

	tmp = I + P;
	tmp2 = LEN + 3;
	while (tmp > 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tmp--;
	}
	write_str(param, STR);
	if (mode == 1)
	{
		write(1, "   ", 3);
		while (tmp2 > 0)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			tmp2--;
		}
		while (tmp < I)
		{
			if ((tmp + P) % SIZE == 0)
				tputs(tgetstr("do", NULL), 1, tputs_putchar);
			else
				tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			tmp++;
		}
	}
}

void					remalloc_cat(char **s1, char *s2)
{
	int					len;
	char				*str;

	len = ft_strlen(*s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * len);
	str = ft_strcpy(str, *s1);
	str = ft_strcat(str, s2);
	free(*s1);
	*s1 = str;
}

static void				insert_char(char **s, char *buf, int i)
{
	char				*str;

	str = ft_strnew(i + 2);
	str = ft_strncpy(str, *s, i);
	str = ft_strcat(str, buf);
	remalloc_cat(&str, (*s + i));
	free(*s);
	*s = str;
}

static void				del_char(char **s, int i)
{
	char				*str;

	str = ft_strnew(i + 1);
	str = ft_strncpy(str, *s, i);
	remalloc_cat(&str, (*s + i + 1));
	free(*s);
	*s = str;
}

void					char_del(t_param *param, char *buf)
{
	if (BUF == DELETE && I < LEN)
	{
		tputs(tgetstr("dc", NULL), 1, tputs_putchar);
		del_char(&STR, I);
		LEN--;
	}
	else if (BUF == B_SPACE && I != 0)
	{
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
		tputs(tgetstr("dc", NULL), 1, tputs_putchar);
		I--;
		del_char(&STR, I);
		LEN--;
	}
	refresh_screen(param, 1);
}

void					char_insert(t_param *param, char *buf)
{
	if (I + P != LEN_MAX - 1 && LEN + P < LEN_MAX - 1)
	{
//		tputs(tgetstr("im", NULL), 1, tputs_putchar);
		if (I == LEN)
			remalloc_cat(&STR, buf);
		else
			insert_char(&STR, buf, I);
		LEN++;
		ft_putstr(buf);
		I++;
//		tputs(tgetstr("ei", NULL), 1, tputs_putchar);
	}
	if (I == LEN)
		refresh_screen(param, 0);
	else
		refresh_screen(param, 1);
}
