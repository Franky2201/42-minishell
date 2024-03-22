/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:02:39 by rkersten          #+#    #+#             */
/*   Updated: 2023/04/06 17:02:43 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst && del)
	{
		while (*lst != NULL)
		{
			next = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = next;
		}
	}
}
