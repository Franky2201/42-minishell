/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:03:21 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/27 20:46:26 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst && f != NULL)
	{
		temp = lst;
		while (temp != NULL)
		{
			f(temp->content);
			temp = temp->next;
		}
	}
}
