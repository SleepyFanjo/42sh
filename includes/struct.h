/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:02:14 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/17 16:02:11 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define Q_STR		(42)
# define Q_CMD		(1)
# define Q_ARG		(2)
# define Q_FILE		(3)
# define Q_LINK		(4)
# define Q_CTRL		(5)
# define Q_EXE		(6)
# define Q_SHELL	(7)
# define Q_SPACE	(0)
# define Q_PIPE		(0)
# define Q_AND		(1)
# define Q_OR		(2)
# define Q_SEP		(3)
# define Q_SIMPLE	(0)
# define Q_DOUBLE	(1)
# define IN_B		(0)
# define OUT_B		(1)

typedef struct		s_cmd
{
	char			*cmd;
	char			**arg;
	int				pipe_in;
	int				pipe_out;
	int				fd_in;
	int				fd_out;
	char			*file_in;
	char			*file_out;
	int				in_mode;
	int				out_mode;
	int				next_cmd;
	int				return_val;
}					t_cmd;

typedef struct		s_list
{
	void			*elem;
	struct s_list	*next;
}					t_list;

typedef struct		s_token
{
	char			*name;
	char			type;
	char			is_inhib;
}					t_token;

#endif
