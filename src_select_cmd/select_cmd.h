/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenouf- <jrenouf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:32:42 by jrenouf-          #+#    #+#             */
/*   Updated: 2014/02/08 15:24:45 by jrenouf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL3_H
# define MINISHELL3_H

# include <sys/ioctl.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <term.h>
# include "../libft/includes/libft.h"

# define UP			4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define RETURN		10
# define SPACE		32
# define B_SPACE	127
# define DELETE		2117294875
# define END		4610843
# define HOME		4741915
# define ALT_LEFT	1146821403
# define ALT_RIGHT	1130044187

# define BUF		*(unsigned int *)buf

# define I			param->i
# define P			param->prompt
# define LEN		param->len
# define LEN_MAX	param->len_max
# define STR		param->str

typedef struct		s_param
{
	int				i;
	int				len;
	int				len_max;
	int				prompt;
	char			*str;
}					t_param;

int					tputs_putchar(int c);
void				char_del(t_param *param, char *buf);
void				char_insert(t_param *param, char *buf);
void				sideways(t_param *param, char *buf);
void				extreme_sideways(t_param *param, char *buf);
void				word_jump_left(t_param *param);
void				word_jump_right(t_param *param);
int					set_term(void);
int					unset_term(void);
int					ft_prompt(char **env);
#endif
