/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:12:45 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:12:06 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
