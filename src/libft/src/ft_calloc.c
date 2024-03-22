/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:03:51 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/29 08:01:15 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	range;

	range = count * size;
	if (size != 0 && count != (range / size))
		return (0);
	ptr = (void *) malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', size * count);
	return (ptr);
}
