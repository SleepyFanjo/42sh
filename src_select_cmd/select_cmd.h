/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:32:42 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/11 14:09:56 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_CMD_H
# define SELECT_CMD_H

# include <sys/ioctl.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <term.h>
# include "../libft/libft.h"

# define RETURN		10
# define TAB		9
# define SPACE		32
# define B_SPACE	127
# define UP			4283163
# define DOWN		4348699
# define RIGHT		4414235
# define LEFT		4479771
# define END		4610843
# define HOME		4741915
# define ALT_UP		1096489755
# define ALT_DOWN	1113266971
# define ALT_LEFT	1146821403
# define ALT_RIGHT	1130044187
# define DELETE		2117294875

# define BUF		*(unsigned int *)buf

# define I			param->i
# define P			param->prompt
# define LEN		param->len
# define LEN_MAX	param->len_max
# define STR		param->str
# define SIZE		param->size

typedef struct		s_param
{
	int				i;
	int				len;
	int				len_max;
	int				size;
	int				prompt;
	char			*str;
}					t_param;

int					tputs_putchar(int c);
int					char_del(t_param *param, char *buf);
int					char_insert(t_param *param, char *buf);
int					sideways(t_param *param, char *buf);
int					extreme_sideways(t_param *param, char *buf);
int					word_jump_left(t_param *param, char *buf);
int					word_jump_right(t_param *param, char *buf);
int					go_down(t_param *param, char *buf);
int					go_up(t_param *param, char *buf);
int					tab_key(t_param *param, char *buf);
int					set_term(void);
int					unset_term(void);
int					ft_prompt(char **env);
char				*select_cmd(int nb);
void				go_left(t_param *param);
void				go_right(t_param *param);
void				write_str(t_param *param, char *str);
void				refresh_screen(t_param *param, int mode);

int					ft_autocomplete(t_param *param);

typedef int			(*t_key)(t_param *, char *);

static const t_key	key_tab[] =
{
					&char_insert,
					&char_del,
					&sideways,
					&extreme_sideways,
					&word_jump_left,
					&word_jump_right,
					&go_down,
					&go_up,
					&tab_key,
					NULL
};

#endif
