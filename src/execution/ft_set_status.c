/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:21:39 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 15:45:07 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_set_status(t_list *parser, size_t i, int status)
{
	t_parser	*content;

	content = (t_parser *)parser->content;
	while (i != content->i && parser->next)
	{
		parser = parser->next;
		content = (t_parser *)parser->content;
	}
	if (content->exit_status)
		return ;
	if (WIFEXITED(status))
		content->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			write(1, "Quit: 3\n", 8);
		content->exit_status = 128 + WTERMSIG(status);
	}
	else if (WIFSTOPPED(status))
		content->exit_status = WSTOPSIG(status);
}
