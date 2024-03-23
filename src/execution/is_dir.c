/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:05:02 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/23 18:07:04 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	is_dir(char *s, int *p)
{
	struct stat	statbuf;

	if (stat(s, &statbuf) == 0 && S_ISDIR(statbuf.st_mode) && ft_strchr(s, '/'))
	{
		*p = 126;
		if (access(s, X_OK))
			return (print_error(NULL, s, strerror(errno)));
		return (print_error(NULL, s, "Is a directory"));
	}
	else if (errno == ENOENT || (statbuf.st_mode && !S_IXUSR))
	{
		access(s, R_OK);
		*p = 127;
		if (errno == EACCES)
			*p = 126;
		if (ft_strchr(s, '/'))
			return (print_error(NULL, s, strerror(errno)));
		return (print_error(NULL, s, "command not found"));
	}
	else if (s && access(s, X_OK | R_OK))
	{
		*p = 126;
		return (print_error(NULL, NULL, strerror(errno)));
	}
	return (false);
}
