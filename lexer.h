/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:42:24 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/10 16:37:36 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define INPUT_REDIRECTION "<"
# define OUTPUT_REDIRECTION ">"
# define HERE_DOC "<<"
# define OUTPUT_APPEND_REDIRECTION ">>"
# define PIPE "|"

typedef struct s_lexer_node
{
	char				*str;
	char				quote;
	bool				closed_quote;
	char				separator;
	struct s_lexer_node	*next;
}	t_lexer_node;

typedef struct	s_input
{
	char				*prompt;
	struct s_lexer_node *list;
}	t_input;

#endif
