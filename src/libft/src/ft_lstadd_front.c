/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:02:14 by rkersten          #+#    #+#             */
/*   Updated: 2023/04/06 17:02:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (lst && node != NULL)
	{
		node->next = *lst;
		(*lst)->previous = node;
		*lst = node;
	}
}
