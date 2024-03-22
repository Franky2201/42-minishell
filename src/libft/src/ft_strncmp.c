/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:59:35 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/12 14:59:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i]
		&& n != 0)
	{
		if (s1[i] == '\0')
			break ;
		i++;
		n--;
	}
	if (n == 0 && i != 0)
		i--;
	if (s1[i] == s2[i])
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
