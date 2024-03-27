/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:10:27 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/27 16:14:59 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_newstr(char	*str, char *value, size_t var_len, size_t index)
{
	size_t	str_len;
	size_t	val_len;
	size_t	new_len;
	char	*new_str;

	str_len = ft_strlen(str);
	val_len = ft_strlen(value);
	new_len = str_len - var_len + val_len;
	new_str = (char *)calloc(new_len, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcat(new_str, str, index + 1);
	ft_strlcat(new_str, value, index + val_len + 1);
	ft_strlcat(new_str, str + index + var_len + 1, new_len);
	return (new_str);
}

char	*ft_rewrite_str(char *str, size_t index, \
						t_list *env, char *exit_status)
{
	t_env	*variable;
	size_t	var_len;

	if (str[index + 1] == '?')
		return (ft_newstr(str, exit_status, 1, index));
	var_len = ft_varlen(str + index + 1);
	while (env != NULL)
	{
		variable = (t_env *)env->content;
		if (ft_strncmp(str + index + 1, variable->name, var_len) == 0)
			return (ft_newstr(str, variable->value, var_len, index));
		env = env->next;
	}
	return (ft_newstr(str, "", var_len, index));
}

int	ft_do_replace(t_list *lexer, t_expand *exp, bool clean_quotes, ssize_t *i)
{
	char	*temp;
	t_lexer	*node;

	node = (t_lexer *)lexer->content;
	temp = node->str;
	node->str = ft_rewrite_str(node->str, *i, exp->env, exp->status);
	free(temp);
	if (node->str == NULL)
		return (1);
	if (clean_quotes)
	{
		node->str = ft_clean_spaces(lexer);
		if (!node->str)
			return (1);
		if (node->closed_quote && ft_new_word(node->str, (size_t *)i))
		{
			ft_split_node(lexer, *i);
			return (1);
		}
	}
	return (0);
}

void	*ft_replace_variables(t_list *lexer, t_list *env,
								char *exit_status, bool clean_quotes)
{
	ssize_t		i;
	char		quote;
	t_lexer		*node;
	t_expand	exp;

	node = (t_lexer *)lexer->content;
	if (clean_quotes)
		node->str = ft_expand_home(node->str, env, lexer);
	if (node->str == NULL)
		return (NULL);
	exp.env = env;
	exp.status = exit_status;
	quote = '\0';
	i = 0;
	while ((size_t)i < ft_strlen(node->str))
	{
		if (ft_is_a_variable(node, &quote, &i, clean_quotes))
		{
			if (ft_do_replace(lexer, &exp, clean_quotes, &i) != 0)
				return ((void *)node->str);
		}
		else
			i++;
	}
	return ((void *)node->str);
}

void	*ft_expand(t_shell *data)
{
	t_list	*env;
	t_list	*current;
	char	*exit_status;
	int		hd;

	exit_status = ft_itoa(data->exit);
	if (exit_status == NULL)
		return (NULL);
	env = data->env;
	current = data->lexer;
	while (current != NULL)
	{
		ft_set_separator_flag((t_lexer *)current->content);
		hd = ft_strncmp(((t_lexer *)current->content)->str, "<<", 2);
		if (!hd)
			current = current->next;
		else if (ft_replace_variables(current, env, exit_status, true) == NULL)
		{
			free(exit_status);
			return (NULL);
		}
		current = current->next;
	}
	free(exit_status);
	return ((void *)data->lexer);
}
