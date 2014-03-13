/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:32:42 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/03/13 15:56:00 by jrenouf-         ###   ########.fr       */
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
# include <signal.h>
# include "../libft/libft.h"

# define C_C		3
# define C_D		4
# define TAB		9
# define RETURN		10
# define SPACE		32
# define B_SPACE	127
# define UP			4283163
# define DOWN		4348699
# define RIGHT		4414235
# define LEFT		4479771
# define END		4610843
# define HOME		4741915
# define ALT_LEFT	1146821403
# define ALT_RIGHT	1130044187
# define DELETE		2117294875

# define BUF		*(unsigned int *)buf

# define I			param->i
# define P			param->prompt
# define P_LINE		param->p_line
# define LEN		param->len
# define LEN_MAX	param->len_max
# define STR		param->str

# define H_STR		param->history->str
# define H_NEXT		param->history->next
# define H_PREV		param->history->prev

typedef struct			s_history
{
	char				*str;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

typedef struct		s_param
{
	int				i;
	int				len;
	int				len_max;
	int				prompt;
	char			*p_line;
	char			*str;
	t_history		*history;
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
int					set_term(void);
int					unset_term(void);
int					ft_prompt(char **env);
char				*select_cmd(int nb, char *str);
void				go_left(t_param *param);
void				go_right(t_param *param);
void				write_str(char *p_line, char *str);
void				refresh_screen(t_param *param, int mode);
void				sc_clear(int sig);
int					get_lenmax(void);
t_param				*save_param(t_param *param);
void				init_param(t_param *param, int nb, char *str);
void				*j_malloc(size_t byte);
void				exleft(int tmp);

#endif
