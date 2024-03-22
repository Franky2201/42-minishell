/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:33:50 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/13 20:52:40 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	dup_value(char *str, int option, t_env *var)
{
	char	c;
	char	*temp;

	c = '=';
	if (option == EXPORT
		&& ft_strnstr(str, "+=", ft_strlen(str)))
		c = '+';
	else if (option == EXPORT)
		option--;
	temp = ft_strchr(str, c);
	if (!temp)
		var->name = ft_substr(str, 0, ft_strlen(str));
	else
	{
		var->name = ft_substr(str, 0, ft_substr_len(str, c));
		if (*temp)
			var->value = ft_substr(temp, option, ft_strlen(temp + option));
		else
			var->value = ft_strdup("");
	}
	if (!var->name || (temp && !var->value))
		return (1);
	return (0);
}

int	init_env(char **env, size_t i, t_list **lst)
{
	t_env	*var;
	t_list	*node;

	if (!env[i] || i == SIZE_MAX)
		return (0);
	var = (t_env *)ft_calloc(1, sizeof(*var));
	if (!var)
		return (1);
	if (dup_value(env[i], ENV, var))
		return (1);
	node = ft_lstnew((void *)var);
	if (!node)
		return (1);
	if (lst)
		ft_lstadd_back(lst, node);
	return (init_env(env, i + 1, lst));
}
