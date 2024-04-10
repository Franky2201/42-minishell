/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:56:12 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/29 18:25:39 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lexer.h"

void	ft_free_lexer_node(void *content)
{
	t_lexer	*node;

	node = (t_lexer *)content;
	if (node != NULL)
	{
		free(node->str);
		free(node);
	}
}

t_list	*ft_split_node(t_list *node, size_t index)
{
	char	*src;
	t_lexer	*content;

	content = (t_lexer *)node->content;
	src = content->str;
	content->str = ft_substr(src, 0, index);
	if (content->str == NULL)
		return (NULL);
	node = ft_add_lexer_node(&node);
	if (node == NULL)
		return (NULL);
	content = (t_lexer *)node->content;
	content->str = ft_strdup(src + index);
	free(src);
	return (node);
}

t_list	*ft_add_lexer_node(t_list **list)
{
	t_lexer	*content;
	t_list	*node;

	content = (t_lexer *)calloc(1, sizeof(t_lexer));
	if (!content)
		return (NULL);
	content->closed_quote = true;
	node = ft_lstnew(content);
	if (node == NULL)
		return (NULL);
	ft_lstinsert(list, node);
	return (node);
}
