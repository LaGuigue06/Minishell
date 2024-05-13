/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:45:56 by laguigue          #+#    #+#             */
/*   Updated: 2024/04/08 11:19:16 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	get_trim_line(t_data *data)
{
	char	*temp;

	temp = ft_strtrim(data->line, " ");
	if (temp == NULL)
		error(MALLOC_ERROR, 0, data);
	free(data->line);
	data->line = temp;
	if (data->line == NULL || data->line[0] == '\0'
		|| (data->line[0] >= 9 && data->line[0] <= 13)
		|| (data->line[0] == ':' && data->line[1] == '\0')
		|| data->line[0] == '!')
		reset_data(data);
}

void	lexer(t_data *data)
{
	get_trim_line(data);
	parse_quote(data);
	get_lexer(data);
	check_token(data);
}
