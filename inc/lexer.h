/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:42:24 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/22 12:03:43 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../src/ft_fprintf/inc/ft_fprintf.h"
# include "../src/libft/inc/libft.h"
# include "structure.h"
# include "constant.h"
# include <stdio.h>
# define WHITESPACES "\t\n\v\f\r "
# define INPUT_REDIRECTION "<"
# define OUTPUT_REDIRECTION ">"
# define HERE_DOC "<<"
# define OUTPUT_APPEND_REDIRECTION ">>"
# define PIPE "|"

t_list	*ft_add_lexer_node(t_list **list);
bool	ft_check_syntax(t_list *list);
bool	ft_closed_quote(t_list *list);
bool	ft_double_pipe(t_lexer *node, char **str);
bool	ft_first_is_a_pipe(t_list *list, char **str);
void	ft_free_lexer_node(void *content);
bool	ft_invalid_redirection(t_list *list, char **str);
bool	ft_is_a_quote(char c);
bool	ft_is_a_separator(char c);
bool	ft_is_a_space(char c);
bool	ft_is_a_token(char c, bool closed_quote);
bool	ft_is_closing_quote(char c, char quote, bool closed_quote);
bool	ft_is_opening_quote(char c, bool closed_quote);
t_list	*ft_lexer(char *prompt);
bool	ft_set_token(char **dst, char *src);
size_t	ft_skip_separator(char *str);
size_t	ft_skip_token(char *str, bool *closed_quote);
size_t	ft_skip_word(char *str, bool *closed_quote);
t_list	*ft_split_node(t_list *node, size_t index);
void	ft_switch_bool(bool *value);
t_list	*ft_token_segmentation(t_list *list);
t_list	*ft_word_segmentation(char *str, t_list **list);
void	ft_write_error(char *str);
void	*free_malloc(t_list **lst);
#endif
