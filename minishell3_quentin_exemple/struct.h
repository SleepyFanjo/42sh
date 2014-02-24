/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 18:28:32 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/01 14:51:30 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_cmd
{
	char		*cmd;
	char		**arg;
	char		*fd_in;
	char		*end;
	int			pipe;
	char		*fd_out;
	int			fd_mode;
}					t_cmd;

typedef struct		s_lst
{
	t_cmd			*cmd;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_list
{
	char			*str;
	int				cmd;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_pos
{
	int				cursor;
	int				history;
	char			*cmd;
}					t_pos;

typedef unsigned long int t_key;

#endif
