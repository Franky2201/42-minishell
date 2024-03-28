/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:29:59 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 12:10:34 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	ft_close_list(t_list *node, t_list **temp)
{
	t_list	*previous;
	t_list	*next;

	previous = node->previous;
	next = node->next;
	if (previous)
	{
		*temp = previous;
		previous->next = next;
	}
	if (next)
		next->previous = previous;
}

void	ft_free_str(void *content)
{
	if (content)
		free(((t_lexer *)content)->str);
}

void	ft_set_separator_flag(t_lexer *node)
{
	if (!ft_strchr(node->str, '\'') && !ft_strchr(node->str, '\"') \
		&& ft_is_a_separator(node->str[0]))
		node->separator = true;
}

void	ft_clean_lexer(t_shell *d)
{
	t_list	*lexer;
	t_list	*temp;
	t_lexer	*node;

	lexer = d->lexer;
	while (lexer)
	{
		node = (t_lexer *)lexer->content;
		temp = lexer->next;
		if (node && node->str[0] == '\0')
		{
			if (!temp && !lexer->previous)
				d->lexer = NULL;
			else
				ft_close_list(lexer, &temp);
			ft_lstdelone(lexer, &ft_free_str);
		}
		if (!temp)
			break ;
		lexer = temp;
	}
	d->lexer = ft_lstfirst(lexer);
}

int	init_parser(t_shell *d)
{
	t_list	*current;
	t_list	*lexer;

	current = ft_add_parser_node(&d->parser);
	if (!ft_expand(d) || !current)
		return (1);
	ft_clean_lexer(d);
	lexer = d->lexer;
	if (!lexer)
		return (1);
	while (lexer)
	{
		lexer = ft_aggregate(current->content, lexer);
		((t_parser *)(current->content))->i = ft_lstsize(d->parser) - 1;
		if (!lexer)
			continue ;
		current = ft_add_parser_node(&current);
		if (current)
			continue ;
		ft_lstclear(&d->parser, &ft_free_parser_node);
		return (1);
	}
	ft_lstiter(d->parser, &ft_add_builtin);
	return (0);
}
