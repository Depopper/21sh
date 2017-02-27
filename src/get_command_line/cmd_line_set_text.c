/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_set_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:29:41 by aschafer          #+#    #+#             */
/*   Updated: 2016/11/14 19:29:45 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

void	cmd_line_set_text(t_cmd_line *cl, char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	cmd_line_rm_chars(cl);
	while (i < len)
		cmd_line_write(cl, str[i++]);
}
