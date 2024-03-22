/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:49:07 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/28 18:28:28 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_substr_len(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i]
		&& str[i] != c
		&& i++ < SIZE_MAX);
	return (i);
}
