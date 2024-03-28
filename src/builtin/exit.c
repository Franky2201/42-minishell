/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:32:14 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/28 18:49:31 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	is_numeric(char **str)
{
	size_t	i;
	char	*temp;

	temp = ft_strtrim(*str, WHITESPACES);
	if (!temp)
		return (0);
	free(*str);
	*str = temp;
	i = 0;
	if (temp[i] == '-' || temp[i] == '+')
		i++;
	while (temp[i])
	{
		if (temp[i] < '0' || temp[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static	bool	max_val(char *str)
{
	long long int	num;
	char			*dup;

	num = ft_atoi(str);
	dup = ft_llitoa(num);
	if (!dup)
		return (false);
	if (ft_strncmp(str, dup, ft_strlen(str)))
		return (true);
	return (false);
}

static void	ft_set_exit(t_builtin *d)
{
	int64_t	status;

	status = 0;
	if (d->argv[1])
		status = ft_atoi(d->argv[1]);
	d->exit = true;
	d->status = status % 256;
}

int	__exit(t_builtin *d)
{
	if (d->parser_len == 1)
		ft_fprintf(1, "exit\n");
	ft_set_exit(d);
	if (!d->argv[1])
		return (0);
	if (!is_numeric(&d->argv[1]) || max_val(d->argv[1]))
	{
		ft_fprintf(2, "minishell: exit: %s: numeric argument required\n", \
					d->argv[1]);
		d->status = 2;
		return (2);
	}
	else if (ft_tabsize(d->argv) > 2)
	{
		d->exit = false;
		ft_fprintf(2, "minishell: exit: too many arguments\n");
		return (1);
	}
	return (d->status);
}
