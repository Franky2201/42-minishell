/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:34:01 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 17:04:43 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "errno.h"

int	ft_exit_code(t_parser *node)
{
	int	fd;

	fd = open(node->argv[0], O_DIRECTORY);
	if (fd <= 0)
	{
		if (errno == EACCES)
			node->exit_status = 126;
		node->exit_status = 127;
	}
	else
	{
		close(fd);
		if (ft_strchr(node->argv[0], '/'))
			node->exit_status = 126;
		else
			node->exit_status = 127;
	}
	return (node->exit_status);
}
