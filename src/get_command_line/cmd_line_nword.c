/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_nword.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 22:55:36 by aschafer          #+#    #+#             */
/*   Updated: 2016/11/14 19:27:02 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_nword(t_cmd_line *cl)
{
	if (!cl->cursor->next)
		return ;
	cmd_line_mv_right(cl);
	if (cl->cursor->c != ' ' && cl->cursor->prev->c == ' ')
		return ;
	cmd_line_nword(cl);
}
