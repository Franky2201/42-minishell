/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:20:35 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 23:33:46 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exit_shell(t_shell *d, int _exit)
{
	int	tmp;

	tmp = d->status;
	fd(d);
	free_table(d);
	clear_history();
	if (_exit)
		exit(_exit);
	exit(tmp);
}
