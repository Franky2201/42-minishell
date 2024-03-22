/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:35:36 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/21 23:20:12 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

size_t	ft_skip_token(char *str, bool *closed_quote)
{
	size_t	i;
	char	quote;

	i = 0;
	quote = '\0';
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

t_list	*ft_token_segmentation(t_list *list)
{
	t_list	*current;
	t_lexer	*content;
	size_t	i;

	current = list;
	while (current != NULL)
	{
		content = (t_lexer *)current->content;
		content->closed_quote = true;
		i = ft_skip_token(content->str, &content->closed_quote);
		if (content->str[i] != '\0')
		{
			current = ft_split_node(current, i);
			if (current == NULL)
			{
				ft_lstclear(&list, &ft_free_lexer_node);
				return (NULL);
			}
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
	quote = '\0';
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

static	void	*input_not_empty(char c, t_list **current, t_list **lst)
{
	if (c)
	{
		*current = ft_add_lexer_node(current);
		if (*current == NULL)
			return (free_malloc(lst));
	}
	return ((void *)*current);
}

t_list	*ft_word_segmentation(char *str, t_list **list)
{
	t_list	*current;
	t_lexer	*content;
	size_t	i;

	*list = ft_add_lexer_node(list);
	if (*list == NULL)
		return (NULL);
	current = *list;
	while (*str != '\0')
	{
		content = (t_lexer *)current->content;
		i = ft_skip_word(str, &content->closed_quote);
		content->str = ft_substr(str, 0, i);
		if (content->str == NULL)
			return (free_malloc(list));
		while (ft_is_a_space(str[i]))
			i++;
		if (!input_not_empty(str[i], &current, list))
			return (NULL);
		str += i;
	}
	return (*list);
}
