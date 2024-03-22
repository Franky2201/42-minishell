/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:45:40 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 19:07:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_strtolower(unsigned int i, char *str)
{
	(void)i;
	*str = ft_tolower(*str);
}

t_f	*select_builtin(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (!len)
		return (NULL);
	ft_striteri(str, &ft_strtolower);
	if (!ft_strncmp(str, "cd", ft_longest(str, "cd")))
		return (cd);
	if (!ft_strncmp(str, "echo", ft_longest(str, "echo")))
		return (echo);
	if (!ft_strncmp(str, "env", ft_longest(str, "env")))
		return (env);
	if (!ft_strncmp(str, "exit", ft_longest(str, "exit")))
		return (__exit);
	if (!ft_strncmp(str, "export", ft_longest(str, "export")))
		return (_export);
	if (!ft_strncmp(str, "pwd", ft_longest(str, "pwd")))
		return (pwd);
	if (!ft_strncmp(str, "unset", ft_longest(str, "unset")))
		return (unset);
	return (NULL);
}

// int	exec_builtin(t_parser *cmd, t_shell *d)
// {
// 	int		ret;

// 	ret = 0;
// 	if (builtin_error(cmd->argv))
// 		return (1);
// 	d->builtin->argv = cmd->argv;
// 	d->builtin->env = d->env;
// 	ret = cmd->f(d->builtin);
// //	printf("%d\n", cmd->exit_status);
// 	if (cmd->f == __exit && !ret)
// 		ret = d->builtin->status;
// 	if (d->pipe || d->exit)
// 		exit(ret);
// 	return (0);
// }

int	builtin_execution(t_parser *cmd, t_shell *d)
{
	if (builtin_error(cmd->argv))
		return (1);
	d->builtin->argv = cmd->argv;
	d->builtin->env = d->env;
	cmd->exit_status = cmd->f(d->builtin);
	if (cmd->f == __exit && !cmd->exit_status)
		cmd->exit_status = d->builtin->status;
	if (d->pipe || d->builtin->exit)
		exit(cmd->exit_status);
	return (0);
}
