/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:16:38 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/13 14:00:34 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	t_env	*lexic_cmp(t_env *n1, t_env *n2)
{
	if (ft_strncmp(n1->name, n2->name, ft_longest(n1->name, n2->name)) < 0)
		return (n1);
	else
		return (n2);
}

static	void	init(t_list *lst, t_export *d)
{
	d->lst = lst;
	d->node = lst;
	d->i = 0;
	d->end = ft_lstsize(lst);
	d->last_entry = NULL;
}

static	int	skip_previous_entry(t_export *d)
{
	t_list	*tmp;

	tmp = d->lst;
	d->current = (t_env *)tmp->content;
	while (d->last_entry \
			&& ft_strncmp(d->current->name, d->last_entry->name, \
					ft_longest(d->current->name, d->last_entry->name)) <= 0)
	{
		tmp = tmp->next;
		if (!tmp)
			return (1);
		d->current = (t_env *)tmp->content;
	}
	return (0);
}

static	void	find_next_entry(t_export *d)
{
	char	*varname;
	t_list	*tmp;

	tmp = d->lst;
	while (tmp != NULL)
	{
		varname = ((t_env *)(tmp->content))->name;
		if (!d->last_entry || (d->last_entry \
				&& ft_strncmp(varname, d->last_entry->name, \
					ft_longest(varname, d->last_entry->name)) > 0))
			d->current = lexic_cmp(d->current, (t_env *)tmp->content);
		tmp = tmp->next;
	}
	d->last_entry = d->current;
}

void	d_export(t_list *lst)
{
	t_export	d;

	init(lst, &d);
	while (d.i++ != d.end)
	{
		if (skip_previous_entry(&d))
			return ;
		find_next_entry(&d);
		if (ft_strncmp("_", d.current->name, ft_strlen(d.current->name)))
		{
			ft_fprintf(1, "declare -x %s", d.current->name);
			if (d.current->value)
				ft_fprintf(1, "=\"%s\"", d.current->value);
			ft_fprintf(1, "\n");
		}
	}
}
