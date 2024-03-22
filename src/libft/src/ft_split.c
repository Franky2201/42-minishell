/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:48:49 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/05 18:48:49 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	size_t	ft_len_word(const char *s, char *ptr_c)
{
	size_t	i;

	i = 0;
	if (*s != '\0')
	{
		while (*s == *ptr_c && *s != '\0')
			s++;
		while (*s != *ptr_c && *s != '\0')
		{
			i++;
			s++;
		}
	}
	return (i);
}

static size_t	ft_len_tab(const char *s, char *ptr_c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == *ptr_c && *s != '\0')
			s++;
		if (*s != *ptr_c && *s != '\0')
			i++;
		while (*s != *ptr_c && *s != '\0')
			s++;
	}
	return (i);
}

static	char	*ft_fill_word(const char *s, char *ptr_c, char *str)
{
	if (*s != '\0')
	{
		while (*s != '\0' && *s == *ptr_c)
			s++;
		while (*s != *ptr_c && *s != '\0')
		{
			*str = *s;
			s++;
			str++;
		}
		*str = '\0';
	}
	return ((char *)s);
}

static	int	ft_create_word(const char *s, char *ptr_c, char **tab, size_t i)
{
	char		temp;
	size_t		j;
	size_t		k;

	j = 0;
	temp = *ptr_c;
	while (i--)
	{
		k = ft_len_word(s, ptr_c);
		tab[j] = (char *) malloc(sizeof(**tab) * (k + 1));
		if (!tab[j])
		{
			while (j--)
				free(tab[j]);
			free(tab);
			return (0);
		}
		s = ft_fill_word(s, &temp, tab[j]);
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	temp;
	char	**tab;
	size_t	i;

	temp = c;
	tab = NULL;
	if (!s)
		return (NULL);
	i = ft_len_tab(s, &c);
	tab = (char **) malloc(sizeof(*tab) * (i + 1));
	if (!tab)
		return (NULL);
	c = temp;
	if (!ft_create_word(s, &c, tab, i))
		return (NULL);
	tab[i] = NULL;
	return (tab);
}
