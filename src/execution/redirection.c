/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:29:39 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/25 13:51:22 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	_open
	open file with oflags based on token type
*/

static	int	_open(t_rd *rd, t_shell *d)
{
	if (rd->token == INPUT)
		d->fdin = open(rd->filename, O_RDONLY);
	else if (rd->token == OUTPUT)
		d->fdout = open(rd->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (rd->token == APPEND)
		d->fdout = open(rd->filename,
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (rd->token == HEREDOC)
		d->fdin = heredoc(rd, d);
	if (d->fdin < 0 || d->fdout < 0)
	{
		ft_fprintf(2, "minishell: %s: %s\n", rd->filename,
			strerror(errno));
		return (1);
	}
	return (0);
}

static	int	last_redirection(t_list *p)
{
	t_list	*tmp;
	t_rd	*content;

	tmp = p->next;
	while (tmp)
	{
		content = (t_rd *)tmp->content;
		if (content->token == 0 || content->token == 2)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
	_dup2
	handle input/output redirection
	@param ptr : redirection node address
	@param rd : node content address
*/

static int	_dup2(t_list *lst, t_parser *cmd, t_shell *d)
{
	t_rd	*rd;

	rd = (t_rd *)lst->content;
	if (_open(rd, d))
		return (1);
	if (!cmd->argv[0] || (!cmd->is_valid && !cmd->f))
		return (0);
	if ((rd->token == INPUT && !last_redirection(lst))
		|| (rd->token == HEREDOC && !last_redirection(lst)))
	{
		if (rd->token == INPUT
			|| rd->token == HEREDOC)
			if (dup2(d->fdin, STDIN_FILENO) == -1)
				return (print_error("redirection.c", "dup2", NULL));
	}
	if (rd->token == APPEND
		|| rd->token == OUTPUT)
		if (dup2(d->fdout, STDOUT_FILENO) == -1)
			return (print_error("redirection.c", "dup2", NULL));
	return (0);
}

/*
	Iterate through the redirection list and apply _dup2 function to each node
	@param lst : store the address of the redirection list's first node
*/

int	redirection(t_parser *cmd, t_shell *d)
{
	t_list		*tmp;

	tmp = cmd->rd;
	while (tmp)
	{
		if (_dup2(tmp, cmd, d))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
