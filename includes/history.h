/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 16:55:56 by qchevrin          #+#    #+#             */
/*   Updated: 2014/03/13 17:16:42 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H
# define MAX_H_LEN		(100)
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_history
{
	char				*str;
	struct s_history	*next;
	struct s_history	*prev;
}					t_history;

void	add_in_history(t_history **history, char *str);

#endif
