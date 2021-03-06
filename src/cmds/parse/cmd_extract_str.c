/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_extract_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:02:34 by aschafer          #+#    #+#             */
/*   Updated: 2017/02/17 14:13:28 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

#define MAX_SIZE 500
#define TRIG_Q 0
#define TRIG_DQ 1

char	*cmd_extract_str(char **strp)
{
	static char	buffer[MAX_SIZE + 1];
	char		triggers[2];
	int			i;

	ft_bzero(buffer, sizeof(char) * (MAX_SIZE + 1));
	ft_bzero(triggers, sizeof(char) * 2);
	i = 0;
	while (**strp)
	{
		if (i == MAX_SIZE)
			exit_shell("Argument is too big !", 1);
		if (**strp == '\'' && !triggers[TRIG_DQ])
			triggers[TRIG_Q] = !triggers[TRIG_Q];
		else if (**strp == '\"' && !triggers[TRIG_Q])
			triggers[TRIG_DQ] = !triggers[TRIG_DQ];
		else if ((cmd_is_skip_char(**strp) || **strp == ';' || **strp == '|')
		&& !triggers[TRIG_Q] && !triggers[TRIG_DQ])
			break ;
		else
			buffer[i++] = **strp;
		++*strp;
	}
	return (ft_strdup(buffer));
}
