/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:53 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/07 20:46:08 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_pid(t_shell *d)
{
	size_t	i;

	i = alloc_len(d->parser);
	d->pid = ft_calloc(i + 1, sizeof(*(d->pid)));
	if (!d->pid)
		return (1);
	return (0);
}
