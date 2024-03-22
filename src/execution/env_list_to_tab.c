/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:20:15 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/14 13:54:22 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	char	**_free(char **tab, size_t i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static	char	*join(char const *s1, char const *s2)
{
	char	*n;
	char	*tmp;

	tmp = ft_strjoin(s1, "=");
	if (!tmp)
		return (NULL);
	n = ft_strjoin(tmp, s2);
	free(tmp);
	if (!n)
		return (NULL);
	return (n);
}

char	**env_list_to_tab(t_list *lst)
{
	char	**envp;
	size_t	i;
	t_env	*cnt;
	t_list	*tmp;

	envp = (char **)ft_calloc(ft_lstsize(lst) + 1, sizeof(*envp));
	if (!envp)
		return (NULL);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		cnt = (t_env *)tmp->content;
		if (cnt->value)
			envp[i] = join(cnt->name, cnt->value);
		else
			envp[i] = ft_strdup(cnt->name);
		if (!envp[i])
			return (_free(envp, i));
		i++;
		tmp = tmp->next;
	}
	return (envp);
}
