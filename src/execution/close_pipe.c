/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:30:58 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 13:03:53 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	size_t	pid_to_index(pid_t *pids, pid_t pid)
{
	size_t	i;

	i = 0;
	while (pids[i])
	{
		if (pids[i] == pid)
			return (i);
		i++;
	}
	return (0);
}

void	close_pipe(t_shell *d)
{
	int		status;
	pid_t	pid;
	size_t	end;
	size_t	i;

	end = ft_lstsize(d->parser);
	status = 0;
	if (end == 1)
	{
		waitpid(-1, &status, 0);
		ft_set_status(d->parser, 0, status);
		return ;
	}
	while (end--)
	{
		pid = waitpid(-1, &status, 0);
		i = pid_to_index(d->pid, pid);
		ft_set_status(d->parser, i, status);
		if (i > 0)
			i--;
		close(d->pipe[i][WRITE]);
		close(d->pipe[i][READ]);
	}
	return ;
}
