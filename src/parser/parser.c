/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:19:55 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/28 18:46:58 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	ft_name_redirection(t_list **lexer)
{
	t_lexer	*content;

	content = (t_lexer *)(*lexer)->content;
	*lexer = (*lexer)->next;
	if (content->str[0] == '<')
	{
		if (content->str[1] == '\0')
			return (INPUT);
		else
			return (HEREDOC);
	}
	if (content->str[0] == '>')
	{
		if (content->str[1] == '\0')
			return (OUTPUT);
		else
			return (APPEND);
	}
	return (-1);
}

t_list	*ft_add_redirection(t_parser *node, t_list **lexer)
{
	ssize_t	i;
	char	quote;
	t_rd	*content;
	t_list	*redirection;
	t_lexer	*temp;

	redirection = ft_add_redirection_node(&node->rd);
	content = (t_rd *)redirection->content;
	content->token = ft_name_redirection(lexer);
	if (content->token == HEREDOC)
		node->is_hd = true;
	temp = (t_lexer *)(*lexer)->content;
	if (ft_strchr(temp->str, '\'') || ft_strchr(temp->str, '\"'))
	{
		content->hd_expand = false;
		quote = '\0';
		i = 0;
		while ((size_t)i < ft_strlen(temp->str))
		{
			ft_is_a_variable(temp, &quote, &i, true);
			i++;
		}
	}
	content->filename = ft_strdup(temp->str);
	return ((*lexer)->next);
}

static void	ft_write_content(t_lexer *content, t_parser *node, \
								t_list **lexer, ssize_t *j)
{
	if (content->separator && ft_is_a_separator(content->str[0]))
		*lexer = ft_add_redirection(node, lexer);
	else
	{
		node->argv[*j] = content->str;
		*lexer = (*lexer)->next;
		(*j)++;
	}
}

size_t	ft_go_to_pipe(t_list *lexer)
{
	size_t	i;
	t_lexer	*content;

	content = (t_lexer *)lexer->content;
	if (content->str[0] == '|')
		return (-1);
	i = 0;
	while (content && content->str[0] != '|')
	{
		if (content->separator && ft_is_a_separator(content->str[0]))
			lexer = lexer->next;
		else
			i++;
		lexer = lexer->next;
		if (lexer)
			content = (t_lexer *)lexer->content;
		else
			content = NULL;
	}
	return (i);
}

t_list	*ft_aggregate(t_parser *node, t_list *lexer)
{
	ssize_t	i;
	ssize_t	j;
	t_lexer	*content;

	i = ft_go_to_pipe(lexer);
	if (i == -1)
		return (ft_aggregate(node, lexer->next));
	node->argv = (char **)calloc((i + 1), sizeof(char *));
	if (node->argv == NULL)
		return (NULL);
	content = (t_lexer *)lexer->content;
	j = 0;
	while (j < i || content->str[0] == '<' || content->str[0] == '>')
	{
		ft_write_content(content, node, &lexer, &j);
		if (lexer)
			content = (t_lexer *)lexer->content;
		else
			break ;
	}
	node->argv[j] = NULL;
	return (lexer);
}
