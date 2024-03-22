/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:47:06 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/07 22:44:28 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

size_t	alloc_len(t_list *lst)
{
	size_t		i;
	t_parser	*content;
	t_list		*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		content = tmp->content;
		if (content->f != _export
			&& content->f != unset)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
