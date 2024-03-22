/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:04:25 by rkersten          #+#    #+#             */
/*   Updated: 2023/04/06 17:04:28 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_node;

	list_node = NULL;
	list_node = (t_list *) malloc(sizeof(t_list));
	if (!list_node)
		return (NULL);
	if (content == NULL)
		list_node->content = NULL;
	else
		list_node->content = content;
	list_node->next = NULL;
	list_node->previous = NULL;
	return (list_node);
}
