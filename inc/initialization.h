/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:20:28 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/20 14:37:20 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H
# include "structure.h"
int		init_builtin(t_shell *d);
int		init_env(char **env, size_t i, t_list **lst);
void	init_history(void);
int		init_lexer(char *s, t_list **lst);
int		init_minimal_env(t_shell *d);
int		init_parser(t_shell *d);
int		init_pid(t_shell *d);
int		init_pipe(t_shell *d);
int		init_prompt(t_shell *d);
int		init_shell(t_shell *d);
int		init_shlvl(t_shell *d);
void	exit_child(int signal);
#endif
