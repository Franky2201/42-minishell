/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:22:40 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/22 11:24:48 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../src/libft/inc/libft.h"
# include "../src/ft_fprintf/inc/ft_fprintf.h"
# include "../src/gnl/get_next_line.h"
//REMOVE
# include "debug.h"
# include "builtin.h"
# include "constant.h"
# include "environment.h"
# include "execution.h"
# include "free.h"
# include "heredoc.h"
# include "initialization.h"
# include "lexer.h"
# include "parser.h"
# include "structure.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

//bool	child_flag;

size_t	alloc_len(t_list *lst);
int		print_error(char *arg, char *cmd, char *custom);
int		update_cwd(char **str);
void	ft_free_lexer_node(void *ptr);
void	ft_free_parser_node(void *ptr);
void	ft_child_signal(void);
void	_signal(void);
void	next_line(int signal);
void	ft_set_separator_flag(t_lexer *node);
#endif
