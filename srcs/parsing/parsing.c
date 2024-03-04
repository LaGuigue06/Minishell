/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:43:14 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 11:10:30 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*static int	get_type(char *str)
{
	if (ft_strcmp(str, "|"))
		return (PIPE);
	if (ft_strcmp(str, "<"))
		return (REDIRECTION_1_left);
	if (ft_strcmp(str, "<<"))
		return (REDIRECTION_2_left);
	if (ft_strcmp(str, ">"))
		return (REDIRECTION_1_right);
	if (ft_strcmp(str, ">>"))
		return (REDIRECTION_2_right);
	return (WORD);
}

t_list	*parse(char *line)
{
	size_t	index;
	char	**tab_cmd;
	t_list	*cmd_list;

	tab_cmd = ft_split(line, " ");
	if (!tab_cmd)
	{
		free(line);
		return (NULL);
	}
	free(line);
	index = 0;
	cmd_list = NULL;
	while (tab_cmd[index])
	{
		lst_add_back(&cmd_list, tab_cmd[index], get_type(tab_cmd[index]));
		++index;
	}
	return (cmd_list);
}
*/