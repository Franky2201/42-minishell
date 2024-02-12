/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:41:10 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/12 21:10:56 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_switch_bool(bool *value)
{
	if (*value == true)
		*value = false;
	else
		*value = true;
}

bool	ft_is_a_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

bool	ft_is_a_separator(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}

bool	ft_is_a_token(char c, bool closed_quote)
{
	if (!ft_is_a_separator(c) || closed_quote == false)
		return (true);
	return (false);
}
