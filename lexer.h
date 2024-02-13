/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:42:24 by gde-win           #+#    #+#             */
/*   Updated: 2024/02/13 21:22:27 by gde-win          ###   ########.fr       */
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
	bool				closed_quote;
	struct s_lexer_node	*next;
}	t_lexer_node;

typedef struct s_input
{
	char				*prompt;
	struct s_lexer_node	*list;
}	t_input;

int				main(int ac, char **av);
void			ft_clean_quotes(t_lexer_node *list);
t_lexer_node	*ft_clean_word(t_lexer_node *node);
size_t			ft_count_quotes(t_lexer_node *node);
t_lexer_node	*ft_free_list(t_lexer_node *list);
t_lexer_node	*ft_insert_node(t_lexer_node *list);
bool			ft_is_a_quote(char c);
bool			ft_is_a_separator(char c);
bool			ft_is_a_space(char c);
bool			ft_is_a_token(char c, bool closed_quote);
bool			ft_is_closing_quote(char c, char quote, bool closed_quote);
bool			ft_is_opening_quote(char c, bool closed_quote);
t_lexer_node	*ft_lexer(char *prompt);
void			ft_print_list(t_lexer_node *list);
bool			ft_remove_quotes(char *str, char c, \
									char *quote, bool *closed_quote);
size_t			ft_skip_separator(char *str);
size_t			ft_skip_token(char *str, bool *closed_quote);
size_t			ft_skip_word(char *str, bool *closed_quote);
t_lexer_node	*ft_split_node(t_lexer_node *node, size_t index);
void			ft_switch_bool(bool *value);
t_lexer_node	*ft_token_segmentation(t_lexer_node *list);
t_lexer_node	*ft_word_segmentation(char *str);

#endif
