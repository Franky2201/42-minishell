/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:15:19 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/12 21:20:11 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}

void	fd(t_shell *d)
{
	close_fd(d->fdin);
	close_fd(d->fdout);
	close_fd(d->_stdin);
	close_fd(d->_stdout);
	close_fd(d->p->fd1);
	close_fd(d->p->fd2);
}
