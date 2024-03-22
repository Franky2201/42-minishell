/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:55:21 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 14:36:24 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	call_execve(t_parser *cmd, t_shell *shell)
{
	cmd->envp = env_list_to_tab(shell->env);
	if (cmd->envp == NULL)
		return (1);
	cmd->path = set_path(cmd, shell->env, shell->builtin->path);
	ft_child_signal();
	execve(cmd->path, cmd->argv, cmd->envp);
	ft_free_tab((void **)cmd->envp);
	exit(errno);
}

static	int	dup2_pipe(t_shell *d, int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		print_error("exec_cmd.c", "dup2", NULL);
		exit_shell(d, errno);
	}
	return (0);
}

static	void	redir_pipe(t_list *node, t_parser *cmd, t_shell *shell)
{
	if (node->next)
	{
		dup2_pipe(shell, shell->pipe[cmd->i][WRITE], STDOUT_FILENO);
		close(shell->pipe[cmd->i][READ]);
	}
	if (node->previous && !cmd->is_hd)
	{
		dup2_pipe(shell, shell->pipe[cmd->i - 1][READ], STDIN_FILENO);
		close(shell->pipe[cmd->i - 1][WRITE]);
	}
}

void	child_execution(t_list *node, t_shell *shell)
{
	t_parser	*cmd;

	shell->child = true;
	cmd = (t_parser *)(node->content);
	redir_pipe(node, cmd, shell);
	if (redirection(cmd, shell))
		exit_shell(shell, 1);
	if (!cmd->argv[0])
		exit_shell(shell, 0);
	if (cmd->f == NULL
		&& call_execve(cmd, shell))
		exit_shell(shell, 1);
	else
		builtin_execution(cmd, shell);
	exit_shell(shell, 1);
}
