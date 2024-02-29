/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:01:41 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 18:05:10 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lst_add_front(t_list **lst, char *data, int type)
{
	t_list	*new;

	if (!(*lst))
	{
		*lst = lst_new(data, type, NULL);
		if (!(*lst))
			return (0);
		return (1);
	}
	new = lst_new(data, type, NULL);
	if (!new)
		return (0);
	new->next = *lst;
	(*lst)->prev = new;
	(*lst) = new;
	return (1);
}
