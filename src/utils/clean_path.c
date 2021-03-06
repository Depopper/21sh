/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <aschafer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:57:03 by aschafer          #+#    #+#             */
/*   Updated: 2016/11/14 17:57:15 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char	*free_array(char ***array, int len, char *ret)
{
	int i;

	i = 0;
	if (!array[0])
	{
		free((*array));
		(*array) = NULL;
		return (ret);
	}
	while (len >= i)
	{
		if ((*array)[i])
		{
			free((*array)[i]);
			(*array)[i] = NULL;
		}
		i++;
	}
	free(*array);
	(*array) = NULL;
	return (ret);
}

static char	*join_path(char **array, int len)
{
	char	*path;
	int		i;

	i = 1;
	if (array[0])
	{
		path = ft_strdup(array[0]);
		path = ft_strrejoin(path, "/", path);
	}
	else
		path = ft_strnew(1);
	while (len >= i)
	{
		if (array[i])
		{
			path = ft_strrejoin(path, path, "/");
			path = ft_strrejoin(path, path, array[i]);
		}
		i++;
	}
	if (!path[0])
		path = ft_strredup(path, "/");
	return (path);
}

static char	**path_back(char **array, int i)
{
	while (i > 0)
	{
		if (!array[i] || !(ft_strcmp(array[i], "..")))
			i--;
		else
		{
			ft_memdel((void **)&(array[i]));
			return (array);
		}
	}
	return (array);
}

char		*clean_path(char *path)
{
	char	**array;
	int		i;
	int		len;

	i = 0;
	len = 0;
	array = ft_strsplit(path, '/');
	if (!path || !array[0])
		return (free_array(&array, len, ft_strdup("/")));
	while (array[len])
		len++;
	while (i != len)
	{
		if (!(ft_strcmp(array[i], "..")))
		{
			if (i > 0)
				array = path_back(array, i);
			ft_memdel((void **)&(array[i]));
		}
		else if (!(ft_strcmp(array[i], ".")))
			ft_memdel((void **)&(array[i]));
		i++;
	}
	return (free_array(&array, len, join_path(array, len)));
}
