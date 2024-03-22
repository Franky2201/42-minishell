/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:26:20 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/14 14:55:30 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_table(t_shell *d)
{
	if (d->builtin != NULL)
		free(d->builtin->cwd);
	if (!d->is_env)
	{
		free(d->builtin->path);
		ft_free_tab((void **)d->is_env);
	}
	ft_lstclear(&d->env, free_env_node);
	ft_lstclear(&d->lexer, &ft_free_lexer_node);
	ft_lstclear(&d->parser, &ft_free_parser_node);
	free(d->builtin);
	free(d->p);
	free(d->pid);
	free(d->s);
	ft_free_tab((void **)d->pipe);
	ft_memset(d, '\0', sizeof(*d));
}
