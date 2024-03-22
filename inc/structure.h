/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:17:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 11:24:34 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include <stdbool.h>
# include <stdlib.h>
typedef struct s_builtin	t_builtin;
typedef struct s_env		t_env;
typedef struct s_export		t_export;
typedef struct s_rd			t_rd;
typedef struct s_lexer		t_lexer;
typedef	struct s_parser		t_parser;
typedef struct s_shell		t_shell;
typedef struct s_list		t_list;
/*
	Token type enumeration
*/
typedef enum e_token
{
	INPUT,
	OUTPUT,
	HEREDOC, 
	APPEND
}	t_token;

typedef struct s_builtin
{
	bool			exit;
	bool			unset_owd;
	bool			unset_pwd;
	char			*cwd;
	char			*owd;
	char			*path;
	char			**argv;
	int				parser_len;
	int				fd;
	int				last_exit_code;
	unsigned char	status;
	t_list			*env;
}	t_builtin;

typedef int	(t_f)(t_builtin *);

typedef	struct	s_exec
{
	bool		is_fork;
	t_list		*node;
	t_parser	*content;
}	t_exec;

/*
** Environment structure
** @param name : environment variable name
** @param Value : environment variable value
*/

typedef struct s_env
{
	char	*name;
	char	*value;
}	t_env;

/*
** Expand in heredoc structure
*/

typedef struct s_expand
{
	t_list	*env;
	char	*status;
}	t_expand;

/*
** Export structure
** @param 
*/

typedef struct s_export
{
	t_env	*last_entry;
	t_env	*current;
	int		i;
	int		end;
	t_list	*lst;
	t_list	*node;
}	t_export;

/*
** Redirection structure
** @param fd : file descriptor
** @param filename : file name
** @param token : redirection type
*/

typedef struct s_rd
{
	char	*filename;
	int		fd;
	bool	hd_expand;
	t_token	token;
}	t_rd;

typedef	struct s_heredoc
{
	bool		expand;
	char		*line;
	char const	*s;
	int			pipe[2];
	pid_t		pid;
	size_t		byte;
}	t_hd;

/*
** Lexer structure
** @param word : character string, must not contain unquoted token
** @param pos : node's list position
** @param token : redirection type
*/

typedef struct s_lexer
{
	char	*str;
	bool	closed_quote;
	bool	separator;
}	t_lexer;

typedef struct s_parser
{
	bool	is_hd;
	char	*path;
	char	**argv;
	char	**envp;
	size_t	i;
	int		(*f)(t_builtin *);
	int		exit_status;
	t_list	*rd;
}	t_parser;

typedef struct s_prompt
{
	char	*s;
	int		fd1;
	int		fd2;
}	t_prompt;

/*
** Minishell main structure
*/

typedef struct s_shell
{
	//t_cache	cache;
	bool		is_env;
	char		*s;
	char		*tmp;
	char		*path;
	char		**envp;
	char		**env_i;
	int			fdin;
	int			fdout;
	int			_stdin;
	int			_stdout;
	int			status;
	int			exit;
	int			**pipe;
	pid_t		*pid;
	t_builtin	*builtin;
	t_list		*lexer;
	t_list		*parser;
	t_list		*env;
	t_prompt	*p;
}	t_shell;
#endif
