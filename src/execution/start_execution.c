/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:31:57 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 14:38:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	void	check_execution_type(t_exec *p, t_shell *d)
{
	if (!p->is_fork)
		parent_execution(p->node, d);
	else if (!d->pid[p->content->i])
		child_execution(p->node, d);
}

static	void	check_fork(t_exec *p, t_shell *d)
{
	t_parser	*tmp;

	tmp = (t_parser *)p->node->content;
	if (tmp->f == NULL
		|| (tmp->f
			&& d->parser->next))
		p->is_fork = true;
	else
		p->is_fork = false;
}

static	int	set_fork(t_exec *p, t_shell *d, size_t i)
{
	if (!p->is_fork)
		return (0);
	d->pid[i] = fork();
	if (d->pid[i] == -1)
		return (print_error("execution.c", "fork", NULL));
	if (!d->pid[i])
		ft_child_signal();
	if (d->pid[i] && d->pipe && d->pipe[i])
	{
		if (close(d->pipe[i][WRITE]) == -1)
			return (print_error("execution.c", "close", NULL));
	}
	return (0);
}

static	bool	check_access(t_parser *cmd, t_shell *shell)
{
	cmd->path = set_path(cmd, shell->env, shell->builtin->path);
	if (!cmd->path)
	{
		if (errno == ENOMEM)
		{
			cmd->exit_status = 1;
			return (print_error(NULL, NULL,
					strerror(ENOMEM)));
		}
		return (1);
	}
	free(cmd->path);
	return (0);
}

int	start_execution(t_shell *shell)
{
	t_exec	s;

	s.node = shell->parser;
	while (s.node)
	{
		check_fork(&s, shell);
		s.content = (t_parser *)s.node->content;
		if (!s.content->f
			&& check_access(s.content, shell))
		{
			if (errno != ENOMEM)
				redirection(s.content, shell);
			s.node = s.node->next;
			continue ;
		}
		if (set_fork(&s, shell, s.content->i))
			return (1);
		check_execution_type(&s, shell);
		if (s.content->is_hd)
			waitpid(shell->pid[s.content->i], NULL, 0);
		s.node = s.node->next;
	}
	if (s.is_fork)
		close_pipe(shell);
	return (0);
}
