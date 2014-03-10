/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwatrelo <vwatrelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:36:35 by vwatrelo          #+#    #+#             */
/*   Updated: 2014/03/10 16:48:30 by vwatrelo         ###   ########.fr       */
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
char		**g_env;

char		*get_path(char *str, char **envp);
int			get_simple_fd_out(t_cmd *cmd);
int			dup_cmd(t_cmd *cmd);
int			exec_cmd(t_cmd *cmd);
int			get_double_fd_out(t_cmd *cmd);
int			get_file_in(t_cmd *cmd);
int			get_word_in(t_cmd *cmd);
void		launch_cmd(t_list *cmd);
void		launch_fork(t_cmd *cmd);
void		launch_one_cmd(t_cmd *cmd, t_cmd *next);
int			add_in_env(t_cmd *cmd, char ***envp, int *fd_b);
int			exec_builtin(t_cmd *cmd);
void		modify_env(char ***envp, char *env);
int			my_setenv(t_cmd *cmd, int *fd_b);
void		print_env(char **envp, int fd);
void		my_unsetenv(t_cmd *cmd);
void		delete_in_env(t_cmd *cmd, char ***envp);

#endif
