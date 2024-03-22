/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shlvl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:56:43 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/14 15:14:18 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	reset_shlvl(t_shell *d)
{
	t_list	*node;
	t_env	*content;

	content = ft_calloc(1, sizeof(*content));
	if (!content)
		return (1);
	content->name = ft_strdup("SHLVL");
	if (!content->name)
		return (1);
	content->value = ft_strdup("0");
	if (!content->value)
		return (1);
	node = ft_lstnew((void *)content);
	if (!node)
		return (1);
	ft_lstadd_back(&d->env, node);
	return (0);
}

static	int	increment_shlvl(int nb, char **value)
{
	free(*value);
	if (nb >= 999)
	{
		if (nb < 2147483647)
			ft_fprintf(2, "%s%d%s\n", E_SHLVL1, (int)nb, E_SHLVL2);
		nb = 1;
	}
	else if (nb < 0)
		nb = 0;
	*value = ft_itoa(nb);
	if (!*value)
		return (1);
	return (0);
}

int	init_shlvl(t_shell *d)
{
	char	*tmp;
	t_list	*node;

	if (!ft_lstchr("SHLVL", d->env)
		&& reset_shlvl(d))
		return (1);
	node = ft_lstchr("SHLVL", d->env);
	tmp = expand_var("SHLVL", d->env);
	if (!tmp)
		tmp = "0";
	if (ft_strlen(tmp) > 19)
	{
		free(((t_env *)(node)->content)->value);
		((t_env *)(node)->content)->value = ft_strdup("1");
		if (!((t_env *)(node)->content)->value)
			return (1);
		return (0);
	}
	else
		return (increment_shlvl((int)ft_atoi(tmp) + 1,
				&((t_env *)(node)->content)->value));
}
