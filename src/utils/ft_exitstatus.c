/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:19:42 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/20 11:20:00 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_exitstatus(t_shell *d)
{
	t_list	*last;

	last = ft_lstlast(d->parser);
	d->exit = ((t_parser *)last->content)->exit_status;
}
