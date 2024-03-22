/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:48:01 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/13 20:50:42 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	pwd
	Display the current working directory in the standard output.
*/

int	pwd(t_builtin *d)
{
	ft_fprintf(1, "%s\n", d->cwd);
	return (0);
}
