/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:28:09 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/13 20:50:50 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	update_cwd
	Update the current working directory inside shell structure
*/

int	update_cwd(char **str)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!tmp)
	{
		ft_fprintf(2, "%s%s%s\n", ECWD1, ECWD2, strerror(errno));
		tmp = ft_strjoin(*str, "/..");
		if (!tmp)
			return (2);
		free(*str);
		*str = tmp;
		return (1);
	}
	if (*str)
		free(*str);
	*str = tmp;
	return (0);
}
