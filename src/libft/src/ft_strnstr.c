/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:48:53 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/06 19:00:29 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!haystack && len == 0)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	k = ft_strlen(haystack);
	if (k < len)
		len = k;
	i = 0;
	while (haystack[i] != '\0' && len >= ft_strlen(needle))
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}
