/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:20:03 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/03 11:24:03 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "structure.h"

void    print_tab(char **tab);
void	debug_lexer(t_list *lst);
void	debug_parser(t_list *lst);
void	debug_env(t_list *env);
void	debug_parser(t_list *lst);
void    print_parser_json(void *content);

#endif
