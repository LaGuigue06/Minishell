/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:41:49 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 20:31:03 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*lst_new(char *data, int type, t_list *prev)
{
	t_list	*new_list;

	new_list = ft_calloc(sizeof(t_list), 1);
	if (!new_list)
		return (NULL);
	new_list->data = ft_strdup(data);
	if (!new_list->data)
	{
		free(new_list);
		return (NULL);
	}
	new_list->type = type;
	new_list->prev = prev;
	new_list->next = NULL;
	return (new_list);
}
