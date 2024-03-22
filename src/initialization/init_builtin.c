/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:58:10 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/20 11:51:11 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_builtin(t_shell *d)
{
	d->builtin = (t_builtin *)ft_calloc(1, sizeof(*(d->builtin)));
	if (!d->builtin)
		return (1);
	d->builtin->cwd = getcwd(NULL, 0);
	if (!d->builtin->cwd)
		return (1);
	d->builtin->last_exit_code = d->exit;
	return (0);
}
