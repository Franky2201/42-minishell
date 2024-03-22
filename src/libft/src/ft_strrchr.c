/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:58:03 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/06 19:00:33 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i != 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (NULL);
}
