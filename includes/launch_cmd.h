/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:36:35 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/16 12:07:53 by lredoban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_CMD_H
# define LAUNCH_CMD_H

# include <fcntl.h>
# include <signal.h>
# include "struct.h"
# include "../libft/libft.h"
# include "parser.h"
# include "select_cmd.h"

extern char	**environ;
pid_t		g_pid;

char		*get_path(char *str, char **envp);
int			get_simple_fd_out(t_cmd *cmd);
int			dup_cmd(t_cmd *cmd);
int			exec_cmd(t_cmd *cmd);
int			get_double_fd_out(t_cmd *cmd);
int			get_file_in(t_cmd *cmd);
int			get_word_in(t_cmd *cmd);
void		launch_cmd(t_list *cmd);
int			launch_fork(t_cmd *cmd);
int			launch_one_cmd(t_cmd *cmd, t_cmd *next);
int			add_in_env(t_cmd *cmd, char ***envp, int *fd_b);
int			exec_builtin(t_cmd *cmd);
void		modify_env(char ***envp, char *env);
int			my_setenv(t_cmd *cmd, int *fd_b);
void		print_env(char **envp, int fd);
int			my_unsetenv(t_cmd *cmd);
int			delete_in_env(t_cmd *cmd, char ***envp);
int			ft_exit(t_cmd *cmd, int fd);
int			ft_echo(char **arg, int fd);
int			*check_opt(char **arg);
int			env(t_cmd *cmd, char **envp, int fd);
int			move_dir(t_cmd *cmd, char ***envp);
char		**table_cpy(char **table);
int			init_sig(void);
void		kill_cmd(int sig);
void		quit_term(int sig);
void		l_pre_prompt(void);

#endif
