/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringtab_to_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:02:15 by aschafer          #+#    #+#             */
/*   Updated: 2016/11/14 18:02:21 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*stringtab_to_string(char **strings, int begin)
{
	char	*string;

	if (strings[begin])
	{
		string = ft_strdup(strings[begin]);
		begin++;
	}
	else
		return (NULL);
	while (strings[begin])
	{
		string = ft_strrejoin(string, string, " ");
		string = ft_strrejoin(string, string, strings[begin]);
		begin++;
	}
	return (string);
}

char	*strtab_to_string_delim(char **strings, int begin, char *delim)
{
	char	*string;

	if (strings[begin])
	{
		string = ft_strdup(strings[begin]);
		begin++;
	}
	else
		return (NULL);
	while (strings[begin])
	{
		string = ft_strrejoin(string, string, delim);
		string = ft_strrejoin(string, string, strings[begin]);
		begin++;
	}
	return (string);
}
