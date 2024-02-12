/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:39:41 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/12 21:33:17 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	ft_print_list(t_lexer_node *list)
{
	size_t	i;
	char	separator[2];

	separator[1] = '\0';
	i = 0;
	while (list != NULL)
	{
		separator[0] = list->separator;
		printf("[%zu]: $%s$\nclosed_quote: %s\nseparator: %s\n\n", i, list->str, \
				list->closed_quote ? "true" : "false", list->separator ? separator : "NaN");
		list = list->next;
		i++;
	}
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

	if (ac != 1)
		return (printf("usage: ./minishell\n"));
	(void)av;
	str = readline("lexer: ");
	if (str == NULL)
		return (EXIT_FAILURE);
	list = ft_lexer(str);
	if (list == NULL)
		return (EXIT_FAILURE);
	ft_print_list(list);
	free(str);
	ft_free_list(list);
	return (EXIT_SUCCESS);
}
