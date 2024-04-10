/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:11:34 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/29 18:02:53 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	parent_execution(t_list *node, t_shell *d)
{
	t_parser	*cmd;

	cmd = (t_parser *)(node->content);
	if (!cmd || !cmd->argv || !cmd->argv[0] || redirection(cmd, d))
	{
		cmd->exit_status = 1;
		return (1);
	}
	builtin_execution(cmd, d);
	if (dup2(d->_stdin, STDIN_FILENO) == -1
		|| dup2(d->_stdout, STDOUT_FILENO) == -1)
		return (print_error("exec_cmd.c", "dup2", NULL));
	if (d->builtin->exit == true)
		exit_shell(d, 0);
	return (0);
}
