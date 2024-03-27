/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:47:14 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/27 19:40:55 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	ft_print_error(char *str)
{
	ft_fprintf(2, "minishell: export: `%s': ", str);
	ft_fprintf(2, "not a valid identifier\n", str);
	return (1);
}

static int	error(char *str)
{
	char	c;
	size_t	i;

	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (ft_print_error(str));
	if (ft_strnstr(str, "+=", ft_strlen(str)))
		c = '+';
	else
		c = '=';
	i = 0;
	while (str[i] && str[i] != c)
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (ft_print_error(str));
		i++;
	}
	return (0);
}

static	int	append_var(t_env *var, t_list *node)
{
	char	*old;
	char	*new;

	old = ((t_env *)(node->content))->value;
	new = ft_strjoin(old, var->value);
	if (!new)
		return (1);
	free(old);
	((t_env *)(node->content))->value = new;
	free(var->value);
	free(var);
	return (0);
}

static	int	export_var(char *str, t_list *lst)
{
	t_env	*var;
	t_list	*node;

	var = ft_calloc(1, sizeof(*var));
	if (!var)
		return (1);
	if (dup_value(str, EXPORT, var, lst)
		|| !ft_strncmp(var->name, "_", ft_strlen(var->name)))
		return (1);
	node = ft_lstchr(var->name, lst);
	if (!node)
	{
		node = ft_lstnew((void *)var);
		if (!node)
			return (1);
		ft_lstadd_back(&lst, node);
		return (0);
	}
	free(var->name);
	if (!ft_strnstr(str, "+=", ft_strlen(str))
		|| !((t_env *)(node->content))->value)
		init_var((t_env *)(node->content), var);
	else if (append_var(var, node))
		return (1);
	return (0);
}

int	_export(t_builtin *d)
{
	bool	_error;
	size_t	i;

	i = 0;
	_error = false;
	if (d->argv[1])
	{
		while (d->argv[++i])
		{
			if (error(d->argv[i]))
			{
				_error = true;
				continue ;
			}
			else if (export_var(d->argv[i], d->env))
				return (1);
		}
	}
	else
		d_export(d->env);
	if (_error)
		return (1);
	return (0);
}
