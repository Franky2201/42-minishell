/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:36:11 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 12:53:16 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	char	*join(char const *s1, char const *s2)
{
	char	*tmp;
	char	*new;

	tmp = ft_strjoin(s1, "/");
	if (!tmp)
		return (NULL);
	new = ft_strjoin(tmp, s2);
	free(tmp);
	if (!new)
		return (NULL);
	return (new);
}

static	bool	is_dir(char *s, int *p)
{
	struct stat	statbuf;

	if (stat(s, &statbuf) == 0
		&& S_ISDIR(statbuf.st_mode)
		&& ft_strchr(s, '/'))
	{
		*p = 126;
		if (access(s, X_OK))
			return (print_error(NULL, s, strerror(errno)));
		return (print_error(NULL, s, "Is a directory"));
	}
	else if (errno == ENOENT
		|| (statbuf.st_mode && !S_IXUSR))
	{
		*p = 127;
		if (ft_strchr(s, '/'))
			return (print_error(NULL, s, strerror(ENOENT)));
		return (print_error(NULL, s, "command not found"));
	}
	else if (access(s, X_OK))
	{
		*p = 126;
		return (print_error(NULL, NULL, strerror(EACCES)));
	}
	return (false);
}

static	bool	is_reg(char *s, int *p)
{
	struct stat	statbuf;

	if (stat(s, &statbuf) == 0
		&& S_ISREG(statbuf.st_mode)
		&& (statbuf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
		return (0);
	else if (errno == EPERM)
	{
		*p = 126;
		return (print_error(NULL, NULL,
				strerror(EPERM)));
	}
	return (1);
}

static	char	*_access(t_parser *cmd, char **t)
{
	char	*path;
	size_t	i;

	i = 0;
	while (t[i])
	{
		path = join(t[i++], cmd->argv[0]);
		if (!path)
		{
			ft_free_tab((void **)t);
			return (NULL);
		}
		if (!is_reg(path, &cmd->exit_status))
			return (path);
		free(path);
	}
	is_dir(cmd->argv[0], &cmd->exit_status);
	return (NULL);
}

char	*set_path(t_parser *cmd, t_list *env, char *no_env_path)
{
	char	*_path;
	char	**tmp;
	t_list	*node;

	if (!cmd->argv[0])
		return (NULL);
	if (ft_strchr(cmd->argv[0], '/')
		&& is_dir(cmd->argv[0], &cmd->exit_status))
		return (NULL);
	if (!is_reg(cmd->argv[0], &cmd->exit_status))
		return (ft_strdup(cmd->argv[0]));
	node = ft_lstchr("PATH", env);
	if (node)
		tmp = ft_split(((t_env *)(node->content))->value, ':');
	else if (no_env_path)
		tmp = ft_split(no_env_path, ':');
	else
		return (NULL);
	if (!tmp)
		return (NULL);
	_path = _access(cmd, tmp);
	ft_free_tab((void *)tmp);
	return (_path);
}
