/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:39:41 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/11 17:49:11 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_print_list(t_lexer_node *list)
{
	size_t	i;
	char	quote[2];
	char	separator[2];

	quote[1] = '\0';
	separator[1] = '\0';
	i = 0;
	while (list != NULL)
	{
		quote[0] = list->quote;
		separator[0] = list->separator;
		printf("[%zu]: $%s$\nquote: $%s$\nseparator: $%s$\n\n", i, list->str, list->quote ? quote : "NaN", list->separator ? separator : "NaN");
		list = list->next;
		i++;
	}
}

t_lexer_node	*ft_free_list(t_lexer_node *list)
{
	if (list != NULL)
	{
		if (list->next != NULL)
			ft_free_list(list->next);
		free(list->str);
		free(list);
	}
	return (NULL);
}

char	*ft_remove_each_occurence(char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*new_str;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	new_str = (char *)malloc((ft_strlen(str) - count + 1) * sizeof(char));
	if (str == NULL)
		return NULL;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

t_lexer_node	*ft_word_segmentation(char *str)
{
	t_lexer_node	*list;
	t_lexer_node	*current;
	size_t			i;
	size_t			j;

	list = (t_lexer_node *)malloc(sizeof(t_lexer_node));
	if (!list)
		return (NULL);
	current = list;
	i = 0;
	while (str[i] != '\0')
	{
		ft_bzero(current, sizeof(t_lexer_node));
		current->closed_quote = true;
		j = 0;
		while (str[i + j] != '\0' && (str[i + j] != ' ' || current->closed_quote == false))
		{
			if (str[i + j] == '\"' || str[i + j] == '\'')
			{
				if (current->quote == '\0')
				{
					current->quote = str[i + j];
					current->closed_quote = false;
				}
				else if (str[i + j] == current->quote)
					current->closed_quote = true;
			}
			j++;
		}
		current->str = ft_substr(str, i, j);
		if (current->str == NULL)
			return (ft_free_list(list));
		while (str[i + j] == ' ')
			j++;
		i += j;
		if (str[i] != '\0')
		{
			current->next = (t_lexer_node *)malloc(sizeof(t_lexer_node));
			if (current->next == NULL)
				return (ft_free_list(list));
			current = current->next;
		}
	}
	return (list);
}
/*
t_lexer_node	*ft_quote_segmentation(char *str)
{
	t_lexer_node	*list;
	t_lexer_node	*current;
	char			*temp;
	size_t			i;
	size_t			j;

	list = (t_lexer_node *)malloc(sizeof(t_lexer_node));
	if (!list)
		return (NULL);
	current = list;
	i = 0;
	while (str[i] != '\0')
	{
		ft_bzero(current, sizeof(t_lexer_node));
		j = 0;
		if (str[i + j] == '\"' || str[i + j] == '\'')
		{
			current->quote = str[i + j++];
			while (str[i + j] != '\0' && str[i + j] != current->quote)
				j++;
			if (str[i + j] == '\0')
				return (ft_free_list(list));
			j++;
		}
		else
		{
			while (str[i + j] != '\0' \
					&& str[i + j] != '\"' && str[i + j] != '\'')
				j++;
		}
		current->str = ft_substr(str, i, j);
		if (current->str == NULL)
			return (ft_free_list(list));
		if (current->quote != '\0')
		{
			temp = current->str;
			current->str = ft_strtrim(current->str, &current->quote);
			free(temp);
			if (current->str == NULL)
				return (ft_free_list(list));
		}
		i += j;
		if (str[i] != '\0')
		{
			current->next = (t_lexer_node *)malloc(sizeof(t_lexer_node));
			if (current->next == NULL)
				return (ft_free_list(list));
			current = current->next;
		}
	}
	return (list);
}
*/
t_lexer_node	*ft_insert_node(t_lexer_node *list)
{
	t_lexer_node	*node;

	node = (t_lexer_node *)malloc(sizeof(t_lexer_node));
	if (!node)
		return (ft_free_list(list));
	ft_bzero(node, sizeof(t_lexer_node));
	node->next = list->next;
	list->next = node;
	return (node);
}

t_lexer_node	*ft_split_unquoted(t_lexer_node *list)
{
	t_lexer_node	*first;
	char			**temp;
	size_t			i;

	first = list;
	while (list != NULL)
	{
		if (list->quote == '\0')
		{
			temp = ft_split(list->str, ' ');
			if (temp == NULL)
				return (NULL);
			if (*temp != NULL)
				free(list->str);
			else
				*list->str = '\0';
			i = 0;
			while (temp[i] != NULL)
			{
				list->str = temp[i];
				i++;
				if (temp[i] != NULL && ft_insert_node(list) != NULL)
					list = list->next;
			}
			free(temp);
		}
		list = list->next;
	}
	return (first);
}

void	ft_switch_bool(bool *value)
{
	if (*value == true)
		*value = false;
	else
		*value = true;
}

t_lexer_node	*ft_token_segmentation(t_lexer_node *list)
{
	t_lexer_node	*current;
	char			*original_str;
	size_t			i;
	size_t			j;

	current = list;
	while (current != NULL)
	{
		original_str = current->str;
		current->closed_quote = true;
		i = 0;
		j = 0;
		while (original_str[j] != '\0' && ((original_str[j] != '<' && original_str[j] != '>' && original_str[j] != '|') || current->closed_quote == false || original_str[j] == current->separator))
		{
			if (original_str[j] == current->quote)
				ft_switch_bool(&current->closed_quote);
			j++;
		}
		if (original_str[j] != '\0')
		{
			if (i != j)
			{
				current->str = ft_substr(original_str, i, j);
				if (current->str == NULL)
					return (ft_free_list(list));
				ft_insert_node(current);
				current->next->quote = current->quote;
				current = current->next;
			}
			current->separator = original_str[j];
			i = j;
			while (original_str[j] == current->separator)
				j++;
			current->str = ft_substr(original_str, i, j - i);
			if (original_str[j] != '\0')
			{
				ft_insert_node(current);
				current->next->str = ft_strdup(original_str + j);
				current->next->quote = current->quote;
			}
			free(original_str);
		}
		current = current->next;
	}
	return (list);
}

/*
t_lexer_node	*ft_clean_tokens(t_lexer_node *list)
{

		if (current->quote != '\0')
		{
			temp = current->str;
			current->str = ft_remove_each_occurence(current->str, current->quote);
			free(temp);
			if (current->str == NULL)
				return (ft_free_list(list));
		}
}
*/
int	main(int ac, char **av)
{
	t_lexer_node	*list;
	char			*str;
	char			*temp;

	if (ac != 1)
		return (printf("usage: ./minishell\n"));
	(void)av;
	str = readline("lexer: ");
	temp = str;
	str = ft_strtrim(str, " ");
	free(temp);
	if (str == NULL)
		return (EXIT_FAILURE);
	list = ft_word_segmentation(str);
	if (list == NULL)
	{
		free(str);
		return (EXIT_FAILURE);
	}
	list = ft_token_segmentation(list);
	if (list == NULL)
	{
		free(str);
		return (EXIT_FAILURE);
	}
	ft_print_list(list);
	free(str);
	ft_free_list(list);
	return (EXIT_SUCCESS);
}
