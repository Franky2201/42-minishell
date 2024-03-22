/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:41:10 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/12 16:12:34 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

bool	ft_is_a_space(char c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (true);
	return (false);
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
	if (c != '\0' && (!ft_is_a_separator(c) || closed_quote == false))
		return (true);
	return (false);
}
