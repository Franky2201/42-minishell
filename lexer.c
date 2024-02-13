/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:35:36 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/13 17:57:49 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

size_t	ft_skip_token(char *str, bool *closed_quote)
{
	size_t	i;
	char	quote;

	i = 0;
	if (ft_is_a_separator(str[i]))
		return (ft_skip_separator(str));
	else
	{
		while (ft_is_a_token(str[i], *closed_quote))
		{
			if (ft_is_a_quote(str[i]) && *closed_quote == true)
			{
				quote = str[i];
				ft_switch_bool(closed_quote);
			}
			else if (str[i] == quote)
				ft_switch_bool(closed_quote);
			i++;
		}
		return (i);
	}
}

t_lexer_node	*ft_token_segmentation(t_lexer_node *list)
{
	t_lexer_node	*current;
	size_t			i;

	current = list;
	while (current != NULL)
	{
		current->closed_quote = true;
		i = ft_skip_token(current->str, &current->closed_quote);
		if (current->str[i] != '\0')
		{
			current = ft_split_node(current, i);
			if (current == NULL)
				return (ft_free_list(list));
		}
		else
			current = current->next;
	}
	return (list);
}

size_t	ft_skip_word(char *str, bool *closed_quote)
{
	size_t	i;
	char	quote;

	i = 0;
	while (str[i] != '\0' && \
			(!ft_is_a_space(str[i]) || *closed_quote == false))
	{
		if (ft_is_a_quote(str[i]) && *closed_quote == true)
		{
			quote = str[i];
			*closed_quote = false;
		}
		else if (str[i] == quote)
			ft_switch_bool(closed_quote);
		i++;
	}
	return (i);
}

t_lexer_node	*ft_word_segmentation(char *str)
{
	t_lexer_node	*list;
	t_lexer_node	*current;
	size_t			i;

	list = ft_insert_node(NULL);
	if (list == NULL)
		return (NULL);
	current = list;
	while (*str != '\0')
	{
		i = ft_skip_word(str, &current->closed_quote);
		current->str = ft_substr(str, 0, i);
		if (current->str == NULL)
			return (ft_free_list(list));
		while (ft_is_a_space(str[i]))
			i++;
		if (str[i] != '\0')
		{
			current = ft_insert_node(current);
			if (current == NULL)
				return (ft_free_list(list));
		}
		str += i;
	}
	return (list);
}

t_lexer_node	*ft_lexer(char *prompt)
{
	t_lexer_node	*list;

	prompt = ft_strtrim(prompt, " ");
	if (prompt == NULL)
		return (NULL);
	list = ft_word_segmentation(prompt);
	free(prompt);
	if (list == NULL)
		return (NULL);
	list = ft_token_segmentation(list);
	if (list == NULL)
		return (NULL);
	return (list);
}
