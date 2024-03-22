/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:36:06 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/12 18:36:08 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

bool	ft_set_token(char **dst, char *src)
{
	*dst = src;
	return (true);
}

void	ft_write_error(char *str)
{
	ft_putstr_fd("bash: syntax error near unexpected token `", STDERR);
	if (str == NULL)
		ft_putstr_fd("newline", STDERR);
	else
		write(STDERR, str, 2);
	write(STDERR, "'\n", 2);
}

bool	ft_check_syntax(t_list *list)
{
	char	*token;

	token = NULL;
	if (!ft_closed_quote(list))
		ft_putstr_fd("bash: syntax error: unclosed quote\n", STDERR);
	else if (ft_first_is_a_pipe(list, &token))
		ft_write_error(token);
	else if (ft_invalid_redirection(list, &token))
		ft_write_error(token);
	else
		return (true);
	return (false);
}
