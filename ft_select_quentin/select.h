/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:11:55 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/11 15:21:40 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# include <termios.h>

typedef struct		s_list
{
	char			*str;
	char			mode;
	char			is_begin;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_param
{
	char			*term;
	struct termios	old_term;
	t_list			*list;
}					t_param;

struct termios	ft_make_raw(void);
void			ft_error(char *str);
void			ft_puterror(char *str);
t_list			*init_list(int argc, char **argv);
t_list			*new_elem_list(char *str, int mode);
void			fill_list(int argc, char **argv, t_list **list);
void			clean_list(t_list **list);
void			delete_elem_list(t_list **list);
int				get_size_list(t_list *list);
int				size_max_list(t_list *list);
struct winsize	get_term_size(void);
void			print_list(struct winsize size, t_list *list);
void			clear_term(void);
int				tput_putchar(int c);
void			print_correct(t_list *elem);
void			modify_list(t_list **list, char *buff);
t_list			*get_begin_list(t_list *list);
void			return_to_shell(t_list *list);
void			get_read(char *read_buff, t_param param);
void			exit_clean(t_param param, int mode);

#endif
