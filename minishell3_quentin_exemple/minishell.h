/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:22:35 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 14:51:24 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define UP_K			(4283163)
# define DOWN_K			(4348699)
# define LEFT_K			(4479771)
# define RIGHT_K		(4414235)
# define CTRL_D_K		(4)
# define DEL_L_K		(127)
# define DEL_R_K		(2117294875)
# define ALT_L_K		(1146821403)
# define ALT_R_K		(1130044187)
# define HOME_K			(4741915)
# define END_K			(4610843)
# define HISTORY_LEN	(10)
# define RD_SIZE		(4096)
# include "struct.h"

void		free_table(char ***table);
void		ft_error(char *str, char *str_2, int mode);
void		parse_cmd(char *cmd, char **path, char ***envp);
char		**get_path(char **envp);
void		reparse_cmd(char *cmd, char **path, char ***envp);
t_cmd		*fill_cmd(char *cmd, int *i);
t_cmd		*init_elem(void);
char		*get_str(char *cmd, int *i);
char		*get_double_quote(char *cmd, int *i);
void		get_fd_in(t_cmd *elem, char *cmd, int *i);
void		get_fd_out(t_cmd *elem, char *cmd, int *i);
void		get_cmd(t_cmd *elem, char *cmd, int *i);
void		add_in_list(t_lst **list, t_cmd *elem);
void		free_list(t_lst **list);
void		free_cmd(t_cmd *elem);
void		launch_fork(t_lst *list, char **path, char **envp);
char		*get_cmd_input(char **pathlist, char *cmd);
int			find_builtin(t_lst *list, char ***envp);
char		**table_cpy(char **table);
void		move_dir(t_cmd *cmd, char ***envp);
void		ft_exit(t_cmd *cmd);
void		modify_env(char ***envp, char *env);
void		fucking_env(t_cmd *cmd, char **envp);
void		add_in_env(t_cmd *cmd, char ***envp);
void		delete_in_env(t_cmd *cmd, char ***envp);
void		get_signal(void);
void		kill_cmd(int sig);
void		make_raw(void);
void		reset_term(void);
char		*get_input(t_list **history);
void		apply_entry(char *buff, char **input, t_list *history, t_pos *pos);
void		print_input(char *input);
void		move_cursor(int nbr);
int			tput_putchar(int c);
void		add_in_history(char *str, t_list **list);
void		apply_ctrl(t_key c, char **input, t_list *history, t_pos *pos);
void		move_cursor_unit(t_key c, t_pos *pos, char *input);
void		move_cursor_word(t_key c, t_pos *pos, char *input);
void		get_history(t_key c, char **input, t_list *history, t_pos *pos);
void		clear_line(int n);
void		delete_letter(t_key c, char **input, t_pos *pos);
#endif
