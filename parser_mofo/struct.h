/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:02:14 by qchevrin          #+#    #+#             */
/*   Updated: 2014/02/24 17:35:34 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# define Q_STR		(-1)
# define Q_CMD		(0)
# define Q_ARG		(1)
# define Q_NAME		(2)
# define Q_LINK		(3)
# define Q_D_INHIB	(4)
# define Q_U_INHIB	(5)
# define Q_BUILTIN	(6)
# define Q_CTRL		(7)
# define Q_SPACE	(8)

typedef struct		s_list
{
	void			*elem;
	struct s_list	*next;
}					t_list;

typedef struct		s_token
{
	char			*name;
	char			type;
}					t_token;

#endif
