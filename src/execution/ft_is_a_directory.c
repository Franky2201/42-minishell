/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_a_directory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:35:31 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 09:14:39 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <sys/stat.h>

// bool	ft_is_a_directory(char *str)
// {
// 	struct stat	statbuf;

// 	if (stat(str, &statbuf) != 0)
// 		return (false);
// 	if (S_ISREG(statbuf.st_mode))
// 	{
// 		if (access(str, X_OK | R_OK))
// 			ft_fprintf(2, "minishell: %s: Permission denied\n", str);
// 		return (true);
// 	}
// 	else if (S_ISDIR(statbuf.st_mode))
// 	{
// 		if (ft_strchr(str, '/'))
// 			ft_fprintf(2, "minishell: %s: Is a directory\n", str);
// 		else
// 			ft_fprintf(2, "minishell: %s: command not found\n", str);
// 		return (true);
// 	}
// 	else if (ft_strnstr(str, "./", ft_strlen(str)))
// 		ft_fprintf(2, "minishell: %s: command not found\n", str);
// 	// else
// 	// 	ft_fprintf(2, "minishell: %s: No such file or directory\n", str);
// 	// return (true);
// }
