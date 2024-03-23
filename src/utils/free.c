/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:33:09 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/23 16:21:59 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../libft/inc/libft.h"

void	free_rd_node(void *ptr)
{
	t_rd	*tmp;

	tmp = (t_rd *)ptr;
	free(tmp->filename);
}

void	free_lexer_node(void *ptr)
{
	t_lexer	*tmp;

	tmp = (t_lexer *)ptr;
	free(tmp->str);
}

void	free_parser_node(void *ptr)
{
	t_parser	*tmp;

	tmp = (t_parser *)ptr;
	free(tmp->path);
	ft_free_tab((void **)tmp->argv);
	ft_free_tab((void **)tmp->envp);
	ft_lstclear(&tmp->rd, free_lexer_node);
}

void	free_env_node(void *ptr)
{
	t_env	*tmp;

	tmp = (t_env *)ptr;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
}

void	free_current_execution(t_shell *d)
{
	if (d->pipe)
	{
		ft_free_tab((void **)d->pipe);
		d->pipe = NULL;
	}
	free(d->pid);
	d->pid = NULL;
	free(d->s);
	close_fd(d->fdout);
	close_fd(d->fdin);
	d->s = NULL;
	ft_lstclear(&d->lexer, &ft_free_lexer_node);
	ft_lstclear(&d->parser, &ft_free_parser_node);
}
