/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:35:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 12:10:17 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
** print a custom error message in the standard error.
*/

int	print_error(char *arg, char *cmd, char *custom)
{
	if (arg)
		ft_fprintf(2, "minishell: %s: %s: %s\n", arg, cmd,
			strerror(errno));
	else if (cmd && custom)
		ft_fprintf(2, "minishell: %s: %s\n", cmd, custom);
	else
		ft_fprintf(2, "minishell: %s\n", custom);
	return (1);
}
