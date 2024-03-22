/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:58:24 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/22 14:11:17 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static	int	ctrl_d(void)
{
	if (rl_eof_found != 0)
	{
		ft_putstr_fd("exit\n", STDIN_FILENO);
		return (1);
	}
	return (0);
}

static	int	init_current_execution(t_shell *shell)
{
	if (init_lexer(shell->s, &shell->lexer)
		|| init_parser(shell)
		|| init_pipe(shell)
		|| init_pid(shell))
	{
		free_current_execution(shell);
		return (1);
	}
	shell->builtin->parser_len = ft_lstsize(shell->parser);
	return (0);
}

static	int	main_loop(t_shell *d)
{
	while (true)
	{
		_signal();
		d->tmp = readline(d->p->s);
		signal(SIGINT, &next_line);
		if (ctrl_d())
			return (0);
		d->s = ft_strtrim(d->tmp, WHITESPACES);
		free(d->tmp);
		if (d->s && *d->s != '\0')
		{
			add_history(d->s);
			if (init_current_execution(d))
				continue ;
			if (start_execution(d))
				ft_fprintf(d->p->fd1, "%s\n", d->s);
			ft_exitstatus(d);
			ft_fprintf(d->p->fd2, "%s\n", d->s);
		}
		free_current_execution(d);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell		d;

	(void)argv;
	if (argc != 1)
		return (print_error(NULL, NULL, "minishell: usage: ./minishell\n"));
	ft_memset(&d, '\0', sizeof(d));
	if (envp[0])
		d.is_env = true;
	d.envp = envp;
	if (init_shell(&d))
		free_table(&d);
	main_loop(&d);
	fd(&d);
	free_table(&d);
	clear_history();
	return (0);
}
