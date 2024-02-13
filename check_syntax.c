/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:23:02 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/13 21:40:34 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	ft_invalid_redirection(t_lexer_node *list, char **str)
{
	while (list != NULL)
	{
		if (list->str == '|' && list->str + 1 != '\0')
		{
			*str = list->str + 1;
			return (true);
		}
		else if (ft_is_a_separator(list->str) && \
				ft_is_a_separator(list->str + 1 && list->str + 2 != '\0'))
		{
			*str = list->str + 1;
			return (true);
		}
	}
	return (false);
}

bool	ft_unclosed_quote(t_lexer_node *node)
{
	while (list->next != NULL)
		list = list->next;
	return (list->closed_quote);
}

void	ft_check_syntax(t_lexer_node *list)
{
	char	*token;

	while (list != NULL)
	{
		if (!ft_closed_quote(list))
			printf("bash: syntax error: unclosed quote\n");
		else if (ft_invalid_redirection(list, &str))
			printf("bash: syntax error near unexpected token `%s'\n", str)
	}
}
