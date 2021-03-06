/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:28:17 by aschafer          #+#    #+#             */
/*   Updated: 2017/01/30 20:11:17 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_command_line.h"

static	int		**quotes_create_opening_tab(void)
{
	int			**array1;
	int			i;

	i = 0;
	array1 = (int **)malloc(sizeof(int *) * 5);
	while (i < 5)
	{
		array1[i] = (int *)malloc(sizeof(int) * 2);
		array1[i][1] = 0;
		i++;
	}
	array1[0][0] = 39;
	array1[1][0] = 34;
	array1[2][0] = 96;
	array1[3][0] = 124;
	array1[4][0] = 0;
	return (array1);
}

static char		*quotes_add_prompt_ret(char *str, char *new)
{
	if (!str)
		return (ft_strdup(new));
	else
		return (ft_strrejoin(str, str, new));
}

static char		*quotes_parse_array(int **array1)
{
	char	*prompt_ret;

	prompt_ret = NULL;
	if (array1[0][1])
		prompt_ret = quotes_add_prompt_ret(prompt_ret, "quote ");
	else if (array1[1][1])
		prompt_ret = quotes_add_prompt_ret(prompt_ret, "dquote ");
	else if (array1[3][1])
		prompt_ret = quotes_add_prompt_ret(prompt_ret, "pipe ");
	if (array1[2][1])
		prompt_ret = quotes_add_prompt_ret(prompt_ret, "bquote ");
	if (prompt_ret != NULL)
	{
		prompt_ret[ft_strlen(prompt_ret) - 1] = '>';
		prompt_ret = ft_strrejoin(prompt_ret, prompt_ret, " ");
	}
	return (prompt_ret);
}

static int		check_backslash(char *str)
{
	char *tmp;

	if (!(tmp = ft_strchr(str, '\\')))
		return (0);
	tmp++;
	while (*tmp)
	{
		if (*tmp == ' ')
			tmp++;
		else
			return (0);
	}
	return (1);
}

char			*quotes_cmd_opened(char **str)
{
	int		**array1;
	char	*prompt;

	if (!*str)
		return (NULL);
	prompt = NULL;
	array1 = quotes_create_opening_tab();
	array1 = quotes_check_opened(*str, array1);
	prompt = quotes_parse_array(array1);
	cmd_line_free_scope_tab(array1);
	array1 = NULL;
	if (!prompt && check_backslash(*str))
		return (ft_strdup("> "));
	else
		return (prompt);
}
