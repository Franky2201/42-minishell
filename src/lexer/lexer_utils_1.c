/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:33:21 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/21 23:19:16 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

bool	ft_is_opening_quote(char c, bool closed_quote)
{
	if (ft_is_a_quote(c) && closed_quote == true)
		return (true);
	return (false);
}

bool	ft_is_closing_quote(char c, char quote, bool closed_quote)
{
	if (c == quote && closed_quote == false)
		return (true);
	return (false);
}

size_t	ft_skip_separator(char *str)
{
	char	separator;
	size_t	i;

	separator = *str;
	i = 0;
	while (str[i] == separator)
		i++;
	return (i);
}

void	ft_switch_bool(bool *value)
{
	if (*value == true)
		*value = false;
	else
		*value = true;
}

void	*free_malloc(t_list **lst)
{
	ft_lstclear(lst, &ft_free_lexer_node);
	return (NULL);
}
