/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:49:01 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/05 18:49:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s1);
	if (!s1)
		return (NULL);
	str = NULL;
	str = (char *) malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, i + 1);
	return (str);
}
