/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:14:18 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/10 22:37:46 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_history(void)
{
	char	*str;
	int		fd;
	size_t	len;

	fd = open(".input", O_RDONLY);
	if (fd < 3)
		return ;
	str = get_next_line(fd);
	while (str != NULL)
	{
		len = ft_strlen(str);
		if (str[len - 1] == '\n')
			str[len - 1] = '\0';
		if (*str != '\0' && *str != '\n')
			add_history(str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
