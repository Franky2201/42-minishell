/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:45:33 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/05 18:45:33 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int64_t	get_nbr(const char *str)
{
	char	sign;
	int64_t	i;
	int64_t	k;

	sign = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	i = 0;
	k = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += sign * (str[i] - 48);
		i++;
	}
	return (k);
}

int64_t	ft_atoi(const char *str)
{
	int64_t	i;

	i = get_nbr(str);
	return (i);
}
