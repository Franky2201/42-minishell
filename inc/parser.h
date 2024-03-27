/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:18:40 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/27 16:11:37 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../src/ft_fprintf/inc/ft_fprintf.h"
# include "../src/libft/inc/libft.h"
# include "structure.h"
# include "builtin.h"
# include "execution.h"
# include "lexer.h"

void	ft_add_builtin(void *content);
t_list	*ft_add_parser_node(t_list **list);
t_list	*ft_add_redirection(t_parser *node, t_list **lexer);
t_list	*ft_add_redirection_node(t_list **list);
t_list	*ft_aggregate(t_parser *node, t_list *lexer);
void	ft_clean_quotes(char **str, ssize_t *max, char quote);
char	*ft_clean_spaces(t_list *lexer);
int		ft_do_replace(t_list *lexer, t_expand *exp, \
						bool clean_quotes, ssize_t *i);
void	*ft_expand(t_shell *data);
char	*ft_expand_home(char *str, t_list *env, t_list *lexer);
void	ft_free_parser_node(void *content);
size_t	ft_go_to_pipe(t_list *lexer);
bool	ft_is_a_variable(t_lexer *node, char *quote, \
							ssize_t *i, bool clean_quotes);
char	*ft_newstr(char	*str, char *value, size_t var_len, size_t index);
bool	ft_new_word(char *str, size_t *i);
size_t	ft_varlen(char *str);
t_list	*ft_parser(t_list *lexer);
void	*ft_replace_variables(t_list *lexer, t_list *env, \
								char *exit_status, bool clean_quotes);
char	*ft_rewrite_str(char *str, size_t index, \
						t_list *env, char *exit_status);
#endif
