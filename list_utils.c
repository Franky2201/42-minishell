/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:56:12 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/12 20:49:20 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_node	*ft_free_list(t_lexer_node *list)
{
	if (list != NULL)
	{
		if (list->next != NULL)
			ft_free_list(list->next);
		free(list->str);
		free(list);
	}
	return (NULL);
}

t_lexer_node	*ft_split_node(t_lexer_node *node, size_t index)
{
	char	*src;

	src = node->str;
	node->str = ft_substr(src, 0, index);
	if (node->str == NULL)
		return (NULL);
	ft_insert_node(node);
	if (node->next == NULL)
		return (NULL);
	node->next->str = ft_strdup(src + index);
	free(src);
	return (node->next);
}

t_lexer_node	*ft_insert_node(t_lexer_node *list)
{
	t_lexer_node	*node;

	node = (t_lexer_node *)malloc(sizeof(t_lexer_node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_lexer_node));
	node->closed_quote = true;
	if (list == NULL)
		return (node);
	node->next = list->next;
	list->next = node;
	return (node);
}
