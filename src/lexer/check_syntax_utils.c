/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:39:11 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/22 11:20:26 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

bool	ft_double_pipe(t_lexer *node, char **str)
{
	if (node->str[0] == '|' && node->str[1] != '\0')
		return (ft_set_token(str, node->str + 1));
	return (false);
}

bool	ft_invalid_redirection(t_list *list, char **str)
{
	t_lexer	*current;
	t_lexer	*next;

	while (list != NULL)
	{
		current = (t_lexer *)list->content;
		if (ft_is_a_separator(current->str[0]))
		{
			if (ft_double_pipe(current, str))
				return (true);
			else if (ft_is_a_separator(current->str[1]) && \
						current->str[2] != '\0')
				return (ft_set_token(str, current->str + 2));
			else if (list->next == NULL)
				return (true);
			else if (current->str[0] != '|')
			{
				next = (t_lexer *)list->next->content;
				if (ft_is_a_separator(next->str[0]))
					return (ft_set_token(str, next->str));
			}
		}
		list = list->next;
	}
	return (false);
}

bool	ft_first_is_a_pipe(t_list *list, char **str)
{
	t_lexer	*node;

	node = (t_lexer *)list->content;
	if (node->str[0] == '|')
		return (ft_set_token(str, node->str));
	return (false);
}

bool	ft_closed_quote(t_list *list)
{
	list = ft_lstlast(list);
	return (((t_lexer *)list->content)->closed_quote);
}
