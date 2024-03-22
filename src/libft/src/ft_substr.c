/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:50:15 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/05 18:50:15 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;

	if (!s)
		return (NULL);
	if (len >= ft_strlen(s) - start && start < ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	s1 = (char *) malloc(sizeof(*s1) * (len + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
