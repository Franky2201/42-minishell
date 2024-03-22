/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:01:31 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/22 10:37:03 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

size_t	ft_varlen(char *str)
{
	size_t	i;

	i = 0;
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

void	ft_clean_quotes(char **str, ssize_t *max, char quote)
{
	ssize_t	i;
	size_t	new_len;
	char	*new_str;

	new_len = ft_strlen(*str) - 2;
	new_str = (char *)calloc((new_len + 1), sizeof(char));
	if (new_str == NULL)
		return ;
	i = 0;
	while ((*str)[i] != quote)
	{
		new_str[i] = (*str)[i];
		i++;
	}
	i++;
	while (i < *max)
	{
		new_str[i - 1] = (*str)[i];
		i++;
	}
	i++;
	ft_strlcat(new_str, *str + i, new_len + 1);
	free(*str);
	*str = new_str;
	*max -= 2;
}

bool	ft_is_a_variable(t_lexer *node, char *quote, \
							ssize_t *i, bool clean_quotes)
{
	if (ft_is_opening_quote(node->str[*i], node->closed_quote))
	{
		ft_switch_bool(&node->closed_quote);
		*quote = node->str[*i];
	}
	else if (ft_is_closing_quote(node->str[*i], *quote, node->closed_quote))
	{
		ft_switch_bool(&node->closed_quote);
		if (clean_quotes)
			ft_clean_quotes(&node->str, i, *quote);
	}
	else if ((node->closed_quote == true || *quote == '\"') \
				&& node->str[*i] == '$' \
				&& (ft_isalnum(node->str[*i + 1]) || node->str[*i + 1] == '?'))
		return (true);
	return (false);
}

bool	ft_new_word(char *str, size_t *i)
{
	size_t	temp;

	temp = *i;
	while (str[temp] != '\0' && !ft_is_a_quote(str[temp]))
	{
		if (ft_is_a_space(str[temp]))
		{
			*i = temp;
			return (true);
		}
		temp ++;
	}
	return (false);
}

char	*ft_clean_spaces(t_list *lexer)
{
	char	*temp;
	t_lexer	*node;

	node = (t_lexer *)lexer->content;
	temp = node->str;
	node->str = ft_strtrim(node->str, WHITESPACES);
	free(temp);
	return (node->str);
}
