/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:40:18 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/13 19:07:02 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_list	*ft_lstchr(char *str, t_list *lst)
{
	size_t	len;
	t_env	*d;
	t_list	*tmp;

	tmp = lst;
	len = ft_strlen(str);
	while (tmp != NULL)
	{
		d = (t_env *)tmp->content;
		if (len < ft_strlen(d->name))
			len = ft_strlen(d->name);
		if (ft_strncmp(str, d->name, len) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*expand_var(char *varname, t_list *env)
{
	t_list	*tmp;

	tmp = ft_lstchr(varname, env);
	if (!tmp)
		return (NULL);
	if (((t_env *)tmp->content)->value)
		return (((t_env *)tmp->content)->value);
	return (NULL);
}
