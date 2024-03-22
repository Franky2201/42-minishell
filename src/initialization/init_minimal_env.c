/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimal_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:50:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 22:51:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	minimal_env_var(char ***ptr)
{
	(*ptr)[1] = ft_strdup("SHLVL=1");
	if (!(*ptr)[1])
	{
		ft_free_tab((void **)(*env));
		return (1);
	}
	(*ptr)[2] = ft_strdup("_=/usr/bin/env");
	if (!(*ptr)[2])
	{
		ft_free_tab((void **)(*env));
		return (1);
	}
	return (0);
}

static	int	minimal_env(char ***ptr)
{
	char	*tmp;

	*ptr = (char **)ft_calloc(4, sizeof(**ptr));
	if (!*ptr)
		return (1);
	tmp = getcwd(NULL, 0);
	if (!tmp)
		return (1);
	(*ptr)[0] = ft_strjoin("PWD=", tmp);
	free(tmp);
	if (!(*ptr)[0])
		return (1);
	if (minimal_env_var(ptr))
		return (1);
	return (0);
}

static int	minimal_env_path(char **path)
{
	*path = ft_strdup("PATH=/Users/rkersten/.brew/bin:/usr/local/bin:"\
						"/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"\
						":/Users/rkersten/.brew/bin");
	if (!*path)
		return (1);
	return (0);
}

int	init_minimal_env(t_shell *d)
{
	if (minimal_env_path(&d->builtin->path)
		|| minimal_env(&d->env_i))
		return (1);
	return (0);
}
