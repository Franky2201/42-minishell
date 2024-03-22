/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:49:55 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/28 17:47:50 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	void	custom_message(char *str)
{
	if (!ft_strncmp(str, "cd", ft_strlen(str)))
		ft_fprintf(2, "[dir]\n");
	else if (!ft_strncmp(str, "unset", ft_strlen(str)))
		ft_fprintf(2, "[name ...]\n");
	else if (!ft_strncmp(str, "export", ft_strlen(str)))
		ft_fprintf(2, "[name[=value] ...]\n");
	else
		ft_fprintf(2, "\n");
}

int	builtin_error(char **argv)
{
	if (ft_strncmp(argv[0], "echo", ft_strlen(argv[0]))
		&& ft_strncmp(argv[0], "exit", ft_strlen(argv[0]))
		&& argv[1]
		&& argv[1][0] == '-')
	{
		if (ft_strncmp(argv[1], "-", ft_strlen(argv[1])) == 0
			|| ft_strncmp(argv[1], "--", ft_strlen(argv[1])) == 0)
			return (0);
		else
		{
			ft_fprintf(2, "minishell: %s: -%c: invalid option\n", \
						argv[0], argv[1][1]);
			ft_fprintf(2, "%s: usage: %s ", argv[0], argv[0]);
			custom_message(argv[0]);
			return (1);
		}
	}
	return (0);
}
