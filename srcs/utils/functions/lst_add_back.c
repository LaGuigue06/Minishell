/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:51:09 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:59 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	lst_add_back(t_list **lst, char *data, int type)
{
	t_list	*head;

	if (!(*lst))
	{
		*lst = lst_new(data, type, NULL);
		if (!(*lst))
			return (0);
		return (1);
	}
	head = *lst;
	while (head->next)
		head = head->next;
	head->next = lst_new(data, type, head);
	if (!head->next)
		return (0);
	return (1);
}
