/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:01:54 by rkersten          #+#    #+#             */
/*   Updated: 2023/04/06 17:07:44 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*last;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = node;
	node->previous = last;
}
