/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:32:14 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 22:45:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	is_numeric(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static	bool	max_val(char *str)
{
	char	sign;

	sign = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (sign == -1 && ft_strncmp(MIN_VAL, str, ft_strlen(MIN_VAL)) < 0)
		return (true);
	else if (sign == 1 && ft_strncmp(MAX_VAL, str, ft_strlen(MAX_VAL)) < 0)
		return (true);
	return (false);
}

int	__exit(t_builtin *d)
{
	int64_t	status;

	if (d->parser_len == 1)
		ft_fprintf(1, "exit\n");
	if (!d->argv[1])
		return (0);
	status = ft_atoi(d->argv[1]);
	if (is_numeric(d->argv[1])
		|| (ft_strlen(d->argv[1]) >= 19
			&& max_val(d->argv[1])))
	{
		ft_fprintf(2, "minishell: exit: %s: numeric argument required\n", \
					d->argv[1]);
		d->status = 2;
		return (2);
	}
	else if (ft_tabsize(d->argv) > 2)
	{
		ft_fprintf(2, "minishell: exit: too many arguments\n");
		return (1);
	}
	d->exit = true;
	d->status = status % 256;
	return (d->status);
}
