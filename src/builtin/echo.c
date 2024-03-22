/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:43:39 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/14 10:06:23 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	echo
	Iterate throught the argv param and write each (except -option)
	element (null-terminated string)
	on the specified fd.
	support -n option
	@param argv : 2d string array
	@param fd : file descriptor
*/

static	int	skip_option(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i] && argv[i][j++] == '-')
	{
		while (argv[i] && argv[i][j] == 'n' && j++ < SIZE_MAX)
		{
			if (argv[i][j] == '\0')
			{
				i++;
				j = 0;
			}
		}
	}
	return (i);
}

int	echo(t_builtin *d)
{
	size_t	i;
	size_t	j;

	i = skip_option(d->argv);
	j = i - 1;
	while (d->argv[i] && i < SIZE_MAX)
	{
		ft_putstr_fd(d->argv[i], 1);
		if (d->argv[i] && d->argv[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!j)
		write(1, "\n", 1);
	return (0);
}
