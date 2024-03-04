/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <vicalvez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:10:23 by laguigue          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:45 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static int	is_charset(const char c, const char *charset)
{
	size_t	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (1);
		++index;
	}
	return (0);
}

static size_t	ft_count_words(const char *str, const char *charset)
{
	size_t	index;
	size_t	words;

	index = 0;
	words = 0;
	while (str[index])
	{
		if (str[index] && !is_charset(str[index], charset))
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
	char	*result;
	size_t	index;

	index = 0;
	while (str[index] && !is_charset(str[index], charset))
		++index;
	result = ft_calloc(sizeof(char), index);
	if (!result)
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
		if (str[index] && !is_charset(str[index], charset))
		{
			result[index_result++] = ft_strdup_split(str + index, charset);
			if (!result[index_result - 1])
			{
				ft_free_tab(result);
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

	result = ft_calloc(sizeof(char *), ft_count_words(str, charset) + 1);
	if (!result)
		return (NULL);
	return (ft_split2(result, str, charset));
}
