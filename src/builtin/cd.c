/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:40:07 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/27 22:14:21 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	error(char **argv)
{
	DIR		*dir;
	size_t	len;

	len = ft_tabsize(argv);
	if (len == 1
		&& !getenv("HOME"))
		return (print_error(NULL, NULL, "minishell: cd: HOME not set"));
	if (len > 2)
		return (print_error(NULL, NULL, "minishell: cd: too many arguments"));
	if (len == 2 && ft_strncmp(argv[1], "-", ft_strlen(argv[1])) \
				&& ft_strncmp(argv[1], "~", ft_strlen(argv[1])))
	{
		dir = opendir(argv[1]);
		if (!dir)
			return (print_error("cd", argv[1], NULL));
		else
			closedir(dir);
	}
	return (0);
}

static int	no_pwd(t_list *env)
{
	t_env	*tmp1;
	t_list	*node;

	node = ft_lstchr("OLDPWD", env);
	if (!node)
		return (0);
	tmp1 = (t_env *)node->content;
	free(tmp1->value);
	tmp1->value = ft_strdup("");
	if (!tmp1->value)
		return (1);
	return (0);
}

static	int	_pwd(t_builtin *d)
{
	t_env	*tmp1;
	t_env	*tmp2;
	t_list	*node;

	node = ft_lstchr("PWD", d->env);
	tmp1 = (t_env *)node->content;
	node = ft_lstchr("OLDPWD", d->env);
	if (node)
	{
		tmp2 = (t_env *)node->content;
		free(tmp2->value);
		tmp2->value = tmp1->value;
	}
	else
		free(tmp1->value);
	tmp1->value = ft_strdup(d->cwd);
	if (!tmp1->value)
		return (1);
	return (0);
}

static	int	update_env(t_builtin *d)
{
	t_list	*node;

	d->owd = d->cwd;
	update_cwd(&d->cwd);
	if (d->argv[1] && !ft_strncmp(d->argv[1], "-", ft_strlen(d->argv[1])))
		ft_fprintf(1, "%s\n", d->cwd);
	if (!d->unset_pwd)
		d->unset_owd = false;
	if (d->unset_pwd)
	{
		d->unset_owd = true;
		d->unset_pwd = false;
	}
	node = ft_lstchr("PWD", d->env);
	if (!node
		&& no_pwd(d->env))
		return (1);
	else if (node
		&& _pwd(d))
		return (1);
	return (0);
}

int	cd(t_builtin *d)
{
	char	*tmp;

	if (error(d->argv))
		return (1);
	if (d->argv[1] && !ft_strncmp(d->argv[1], "-", ft_strlen(d->argv[1])))
	{
		tmp = expand_var("OLDPWD", d->env);
		if (d->unset_owd)
			return (print_error(NULL, NULL, "minishell: cd: OLDPWD not set"));
		else if (!tmp)
			chdir(d->owd);
		else
			chdir(tmp);
	}
	else if (d->argv[1] && ft_strncmp(d->argv[1], "~", ft_strlen(d->argv[1])))
		chdir(d->argv[1]);
	else if (chdir(expand_var("HOME", d->env)) == -1)
		print_error("cd", expand_var("HOME", d->env), NULL);
	if (update_env(d))
		return (1);
	return (0);
}
