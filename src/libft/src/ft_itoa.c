/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:47:17 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/05 18:47:17 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_strlen_itoa(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_fill_str(char *s, int n)
{
	int		i;
	long	j;

	if (n == 0)
	{
		s[0] = '0';
		return ;
	}
	i = ft_strlen_itoa(n) - 1;
	j = (long) n;
	if (j < 0)
	{
		j *= -1;
		s[0] = '-';
	}
	while (i != 0)
	{
		s[i] = j % 10 + 48;
		j /= 10;
		i--;
	}
	if (n > 0)
		s[0] = j % 10 + 48;
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	s = NULL;
	i = ft_strlen_itoa(n);
	s = (char *) malloc(sizeof(*s) * (i + 1));
	if (!s)
		return (NULL);
	ft_fill_str(s, n);
	s[i] = '\0';
	return (s);
}
