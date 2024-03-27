/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:42:28 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/27 17:46:10 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*ft_find_home(t_list *env)
{
	while (env && ft_strncmp(((t_env *)env->content)->name, "HOME", 5))
		env = env->next;
	if (env)
		return (((t_env *)env->content)->value);
	return (NULL);
}

char	*ft_expand_home(char *str, t_list *env, t_list *lexer)
{
	char	*home;
	char	*new_path;

	if (lexer)
		str = ft_clean_spaces(lexer);
	if (!str || str[0] != '~' || (str[1] != '\0' && str[1] != '/'))
		return (str);
	home = ft_find_home(env);
	if (home)
	{
		new_path = ft_strjoin(home, str + 1);
		if (!new_path)
			return (str);
		free(str);
		return (new_path);
	}
	return (str);
}
