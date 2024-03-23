/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:32:29 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/23 18:05:27 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H
# include "structure.h"

bool	is_dir(char *s, int *p);
int		builtin_execution(t_parser *cmd, t_shell *d);
void	close_pipe(t_shell *d);
void	child_execution(t_list *node, t_shell *d);
char	**env_list_to_tab(t_list *lst);
void	exit_shell(t_shell *d, int _exit);
int		ft_exit_code(t_parser *node);
void	ft_exitstatus(t_shell *d);
bool	ft_is_a_directory(char *str);
void	free_current_execution(t_shell *d);
void	ft_set_status(t_list *parser, size_t i, int status);
char	*set_path(t_parser *cmd, t_list *env, char *no_env_path);
int		parent_execution(t_list *node, t_shell *d);
t_f		*select_builtin(char *str);
int		start_execution(t_shell *shell);
int		redirection(t_parser *cmd, t_shell *d);
#endif
