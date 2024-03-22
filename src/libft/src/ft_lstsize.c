/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:04:44 by rkersten          #+#    #+#             */
/*   Updated: 2023/04/06 17:04:47 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

size_t	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
