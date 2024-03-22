/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:36:42 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/13 20:49:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print(void *ptr)
{
	t_env	*node;

	node = (t_env *)ptr;
	if (node->value)
		ft_fprintf(1, "%s=%s\n", node->name, node->value);
}

int	env(t_builtin *d)
{
	ft_lstiter(d->env, print);
	return (0);
}
