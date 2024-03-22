/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:49:16 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/13 20:50:23 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	error
	Check if unset was called without option,
	if not set retval to indicate the error.
	@param argv : command's argument vector.
	@param retval : command's return value.
*/

static	int	error(char **argv, int *retval)
{
	if (argv[1]
		&& argv[1][0] == '-'
		&& argv[1][1])
	{
		ft_fprintf(2, "minishell: unset: -%c: invalid option\n", argv[1][1]);
		ft_fprintf(2, "unset: usage: unset [name ...]\n");
		*retval = 2;
		return (1);
	}
	return (0);
}

/*
	execute
	Iterate through the environment list
	and delete the node list who match varname.
	@param varname : environment variable name.
	@param env : environment list.
*/

static	void	execute(char *varname, t_builtin *d)
{
	t_list	*tmp;

	tmp = ft_lstchr(varname, d->env);
	if (!tmp)
		return ;
	else if (tmp && !ft_strncmp(varname, "PWD", ft_longest(varname, "PWD")))
		d->unset_pwd = true;
	else if (tmp && !ft_strncmp(varname, "OLDPWD", \
						ft_longest(varname, "OLDPWD")))
		d->unset_owd = true;
	if (tmp->previous != NULL && tmp->next != NULL)
	{
		tmp->previous->next = tmp->next;
		tmp->next->previous = tmp->previous;
	}
	else if (tmp->previous == NULL)
	{
		d->env = tmp->next;
		tmp->next->previous = NULL;
	}
	else if (tmp->next == NULL)
		tmp->previous->next = NULL;
	free_env_node(tmp->content);
	free(tmp);
}

/*
** unset
** Unset the environment variables for wich the name match a string
** of the arguments vector passed as input, except the first string.
** Work only without option.
** @param argv : command's argument vector.
** @param env : store environment list first node address.
*/

int	unset(t_builtin *d)
{
	int		retval;
	size_t	i;

	if (error(d->argv, &retval))
		return (retval);
	i = 0;
	while (d->argv[++i]
		&& i < SIZE_MAX)
	{
		if (d->path
			&& !ft_strncmp(d->argv[i], "PATH", ft_longest(d->argv[i], "PATH")))
		{
			free(d->path);
			d->path = NULL;
		}
		if (!ft_strncmp(d->argv[i], "_", ft_strlen(d->argv[i])))
			continue ;
		execute(d->argv[i], d);
	}
	return (0);
}
