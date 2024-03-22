/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_va.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:10:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/11 17:16:11 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdarg.h>
#include <stdbool.h>

bool	ft_error_va(char *errmsg, ...)
{
	va_list	args;
	char	*arg;

	arg = errmsg;
	write(2, errmsg, ft_strlen(errmsg));
	va_start(args, errmsg);
	while (arg != NULL)
	{
		arg = va_arg(args, char *);
		if (arg != NULL)
			write(2, arg, ft_strlen(arg));
	}
	write(2, "\n", 1);
	va_end(args);
	return (false);
}
