/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:52:32 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/14 15:09:47 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_free_tab(void **ptr)
{
	size_t	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
