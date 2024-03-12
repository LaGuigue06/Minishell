/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laguigue <laguigue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:37:06 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/06 16:52:52 by laguigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	is_charset(const char c, const char *charset)
{
	size_t	index;

	index = 0;
	while (charset[index])
	{
		if (charset[index] == c)
			return (1);
		++index;
	}
	return (0);
}

static size_t	ft_count_word(const char *str, const char *charset)
{
	size_t	words;
	size_t	index;

	words = 0;
	index = 0;
	while (str[index])
	{
		if (!is_charset(str[index], charset))
		{
			++words;
			while (str[index] && !is_charset(str[index], charset))
				++index;
		}
		else
			++index;
	}
	return (words);
}

static char	*ft_strdup_split(const char *str, const char *charset)
{
	size_t	index;
	char	*result;

	index = 0;
	while (str[index] && !is_charset(str[index], charset))
		++index;
	result = ft_calloc(sizeof(char), index + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (str[index] && !is_charset(str[index], charset))
	{
		result[index] = str[index];
		++index;
	}
	result[index] = '\0';
	return (result);
}

static char	**ft_split2(char **result, const char *str, const char *charset)
{
	size_t	index;
	size_t	index_result;

	index = 0;
	index_result = 0;
	while (str[index])
	{
		if (!is_charset(str[index], charset))
		{
			result[index_result++] = ft_strdup_split(str + index, charset);
			if (result[index_result - 1] == NULL)
			{
				free_arr(result);
				return (NULL);
			}
			while (str[index] && !is_charset(str[index], charset))
				++index;
		}
		else
			++index;
	}
	result[index_result] = NULL;
	return (result);
}

char	**ft_split(const char *str, const char *charset)
{
	char	**result;

	result = ft_calloc(sizeof(char *), ft_count_word(str, charset) + 1);
	if (result == NULL)
		return (NULL);
	return (ft_split2(result, str, charset));
}