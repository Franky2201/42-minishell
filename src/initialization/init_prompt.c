/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:17:43 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/20 18:55:52 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_prompt(t_shell *d)
{
	d->p = (t_prompt *)ft_calloc(1, sizeof(*(d->p)));
	if (!d->p)
		return (1);
	init_history();
	d->p->s = PROMPT;
	d->p->fd1 = open(".minishell", O_CREAT | O_WRONLY | O_APPEND, 0600);
	d->p->fd2 = open(".input", O_CREAT | O_WRONLY | O_APPEND, 0600);
	return (0);
}
