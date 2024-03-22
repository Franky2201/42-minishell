/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:34:19 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/08 09:05:55 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	_pipe(int **pip)
{
	size_t	i;

	i = 0;
	while (pip[i])
		pipe(pip[i++]);
	return (0);
}

int	init_pipe(t_shell *d)
{
	size_t	i;
	size_t	j;

	i = ft_lstsize(d->parser) - 1;
	if (i == 0)
		return (0);
	j = i;
	d->pipe = ft_calloc(i + 1, sizeof(*(d->pipe)));
	if (!d->pipe)
		return (1);
	while (i--)
	{
		d->pipe[i] = ft_calloc(2, sizeof(**(d->pipe)));
		if (!d->pipe[i])
		{
			while (i++ != j)
				free(d->pipe[i]);
			free(d->pipe);
			d->pipe = NULL;
			return (1);
		}
	}
	_pipe(d->pipe);
	return (0);
}
