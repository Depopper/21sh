/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_link_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 02:58:03 by aschafer          #+#    #+#             */
/*   Updated: 2017/01/27 21:32:09 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static t_redir	*make_redir(int from, int to)
{
	t_redir *redir;

	redir = (t_redir *)shalloc(sizeof(t_redir));
	redir->from = from;
	redir->to = to;
	return (redir);
}

void			cmd_link_pipe(t_cmd *current, int p[2])
{
	if (current->children)
	{
		pipe(p);
		cmd_push_redir_front(&current->redirs, make_redir(1, p[1]));
		cmd_push_redir_front(&current->children->redirs, make_redir(0, p[0]));
	}
}
