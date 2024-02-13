/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:33:21 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/13 17:20:51 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
