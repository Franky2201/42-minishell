/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:49:41 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/05 18:49:41 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s1;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	s1 = NULL;
	s1 = (char *) malloc(sizeof(*s1) * (i + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
