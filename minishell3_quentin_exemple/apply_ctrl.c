/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qchevrin <qchevrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 13:20:39 by qchevrin          #+#    #+#             */
/*   Updated: 2014/01/29 18:05:51 by qchevrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <libft.h>

void		apply_ctrl(t_key c, char **input, t_list *history, t_pos *pos)
{
	if (c == UP_K || c == DOWN_K)
		get_history(c, input, history, pos);
	if (c == LEFT_K || c == RIGHT_K || c == END_K || c == HOME_K)
		move_cursor_unit(c, pos, *input);
	if (c == CTRL_D_K)
		exit(0);
	if (c == DEL_R_K || c == DEL_L_K)
		delete_letter(c, input, pos);
	if (c == ALT_L_K || c == ALT_R_K)
		move_cursor_word(c, pos, *input);
}
