/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:17:31 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/22 19:20:31 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_longest(char const *s1, char const *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	if (len < ft_strlen(s2))
		len = ft_strlen(s2);
	return (len);
}
