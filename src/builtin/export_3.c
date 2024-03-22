/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:47:01 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/21 22:47:46 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_var(t_env *old, t_env *new)
{
	if (new->value)
	{
		free(old->value);
		old->value = new->value;
	}
	free(new);
}
