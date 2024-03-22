/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:06:46 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 23:34:09 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	next_line(int signal)
{
	if (signal == SIGINT)
		ft_putendl_fd("", 1);
}

static	void	new_line(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 1);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_child_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	_signal(void)
{
	signal(SIGINT, &new_line);
	signal(SIGQUIT, SIG_IGN);
}
