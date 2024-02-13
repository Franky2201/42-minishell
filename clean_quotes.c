/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:01:31 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/13 20:40:29 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

bool	ft_remove_quotes(char *str, char c, char *quote, bool *closed_quote)
{
	if (ft_is_opening_quote(c, *closed_quote))
	{
		ft_switch_bool(closed_quote);
		*quote = c;
		return (true);
	}
	else if (ft_is_closing_quote(c, *quote, *closed_quote))
	{
		ft_switch_bool(closed_quote);
		return (true);
	}
	else
		*str = c;
	return (false);
}

size_t	ft_count_quotes(t_lexer_node *node)
{
	size_t	i;
	size_t	count;
	char	quote;

	i = 0;
	count = 0;
	quote = '\0';
	while (node->str[i] != '\0')
	{
		if (ft_is_opening_quote(node->str[i], node->closed_quote))
		{
			ft_switch_bool(&node->closed_quote);
			quote = node->str[i];
			count++;
		}
		else if (ft_is_closing_quote(node->str[i], quote, node->closed_quote))
		{
			ft_switch_bool(&node->closed_quote);
			count++;
		}
		i++;
	}
	return (count);
}

t_lexer_node	*ft_clean_word(t_lexer_node *node)
{
	size_t	i;
	size_t	j;
	size_t	new_len;
	char	*new_str;
	char	quote;

	new_len = ft_strlen(node->str);
	new_len -= ft_count_quotes(node);
	new_str = (char *)malloc((new_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (node->str[i] != '\0')
	{
		if (!ft_remove_quotes(new_str + j, node->str[i], \
								&quote, &node->closed_quote))
			j++;
		i++;
	}
	new_str[j] = '\0';
	node->str = new_str;
	return (node);
}

void	ft_clean_quotes(t_lexer_node *list)
{
	char	*str;

	while (list != NULL)
	{
		str = list->str;
		ft_clean_word(list);
		free(str);
		list = list->next;
	}
}
