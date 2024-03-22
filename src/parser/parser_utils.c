/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:43:27 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/13 14:00:11 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_add_builtin(void *content)
{
	t_parser	*node;

	node = (t_parser *)content;
	if (node->argv != NULL)
		node->f = select_builtin(node->argv[0]);
}

void	ft_free_redirection_node(void *content)
{
	t_rd	*node;

	node = (t_rd *)content;
	if (node != NULL)
	{
		free(node->filename);
		free(node);
	}
}

void	ft_free_parser_node(void *content)
{
	t_parser	*node;

	node = (t_parser *)content;
	if (node != NULL)
	{
		free(node->argv);
		ft_lstclear(&node->rd, &ft_free_redirection_node);
		free(node);
	}
}

t_list	*ft_add_redirection_node(t_list **list)
{
	t_rd	*content;
	t_list	*node;

	content = (t_rd *)calloc(1, sizeof(t_rd));
	if (!content)
		return (NULL);
	content->hd_expand = true;
	node = ft_lstnew(content);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(list, node);
	return (node);
}

t_list	*ft_add_parser_node(t_list **list)
{
	t_parser	*content;
	t_list		*node;

	content = (t_parser *)calloc(1, sizeof(t_parser));
	if (!content)
		return (NULL);
	node = ft_lstnew(content);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(list, node);
	return (node);
}
