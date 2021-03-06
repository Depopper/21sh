/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:16:27 by aschafer          #+#    #+#             */
/*   Updated: 2015/11/29 23:16:56 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd(t_list **alst, t_list *new)
{
	t_list *curr;

	if (!alst || !new)
		return (NULL);
	if (!*alst)
		return ((*alst = new));
	curr = new;
	while (curr->next)
		curr = curr->next;
	curr->next = *alst;
	return (*alst = new);
}
