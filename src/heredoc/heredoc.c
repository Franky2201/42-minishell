/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:30:49 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 22:49:33 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	char	*expand(char *s, t_list *env, int e_status)
{
	char	*exit;
	t_list	node;
	t_lexer	tmp;

	exit = ft_itoa(e_status);
	if (!exit)
	{
		free(s);
		return (NULL);
	}
	ft_memset(&tmp, '\0', sizeof(tmp));
	tmp.str = s;
	tmp.closed_quote = true;
	node.content = (void *)&tmp;
	s = (char *)ft_replace_variables(&node, env, exit, false);
	if (!s)
	{
		free(s);
		return (NULL);
	}
	return ((char *)s);
}

static	int	child(t_hd *hd, t_shell *d)
{
	int	tmp;

	close(hd->pipe[0]);
	tmp = dup(STDIN_FILENO);
	while (1)
	{
		write(tmp, "> ", 2);
		hd->line = get_next_line(STDIN_FILENO);
		if (hd->expand)
			hd->line = expand(hd->line, d->env, d->status);
		if (!hd->line || !ft_strncmp(hd->line, hd->s, ft_strlen(hd->line) - 1))
		{
			close(hd->pipe[1]);
			close(tmp);
			free(hd->line);
			exit(0);
		}
		write(hd->pipe[1], hd->line, ft_strlen(hd->line));
		free(hd->line);
	}
}

int	heredoc(t_rd *rd, t_shell *d)
{
	t_hd	hd;

	pipe(hd.pipe);
	hd.s = rd->filename;
	hd.expand = rd->hd_expand;
	hd.pid = fork();
	if (hd.pid == 0)
		child(&hd, d);
	else
	{
		close(hd.pipe[1]);
		waitpid(hd.pid, NULL, 0);
	}
	return (hd.pipe[0]);
}
