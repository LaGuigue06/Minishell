/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:12:45 by laguigue          #+#    #+#             */
/*   Updated: 2024/02/29 20:14:15 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	lst_size(t_list *lst)
{
	t_list	*head;
	size_t	size;

	size = 0;
	head = lst;
	while (head)
	{
		head = head->next;
		++size;
	}
	return (size);
}
