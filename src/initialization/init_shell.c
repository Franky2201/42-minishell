/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:03:08 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 22:56:58 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_shell(t_shell *d)
{
	if (init_builtin(d)
		|| init_prompt(d))
		return (1);
	if (d->is_env
		&& init_env(d->envp, 0, &d->env))
		return (1);
	else if (!d->is_env
		&& (init_minimal_env(d)
			|| init_env(d->env_i, 0, &d->env)))
		return (1);
	if (init_shlvl(d))
		return (1);
	d->_stdin = dup(STDIN_FILENO);
	d->_stdout = dup(STDOUT_FILENO);
	return (0);
}
