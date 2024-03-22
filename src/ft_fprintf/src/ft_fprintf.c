/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:23:41 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/18 11:22:48 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fprintf.h"

int	ft_fprintf(int fd, const char *f, ...)
{
	char	*ptr;
	va_list	arg;
	int		ret;

	va_start(arg, f);
	ret = 0;
	ptr = (char *) f;
	while (ptr)
	{
		display_f(fd, ptr, &ptr, &ret);
		if (ret == -1)
			return (-1);
		if (*ptr && is_conv(*(++ptr)))
			display_arg(fd, *ptr, arg, &ret);
		else if (*ptr)
			putchar_fd(fd, *ptr, &ret);
		if (ret == -1)
			return (-1);
		if (!*ptr)
			break ;
		ptr++;
	}
	va_end(arg);
	return (ret);
}

void	display_arg(int fd, char c, va_list arg, int *ptr)
{
	if (c == 'c')
		putchar_fd(fd, va_arg(arg, int), ptr);
	if (c == 's')
		putstr_fd(fd, va_arg(arg, char *), ptr);
	if (c == 'p')
		putptr_fd(fd, va_arg(arg, void *), ptr);
	if (c == 'd' || c == 'i')
		putnbr_fd(fd, va_arg(arg, int), ptr);
	if (c == 'u')
		putnbr_u_fd(fd, va_arg(arg, int), ptr);
	if (c == 'x')
		puthexa_fd(fd, va_arg(arg, int), ptr, "0123456789abcdef");
	if (c == 'X')
		puthexa_fd(fd, va_arg(arg, int), ptr, "0123456789ABCDEF");
}

int	is_conv(char c)
{
	char	*conv;

	conv = "cspdiuxX";
	while (*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}

void	display_f(int fd, char *str, char **ptr, int *ret)
{
	if (*ret == -1)
		return ;
	if (*str && *str != '%')
	{
		*ptr += 1;
		putchar_fd(fd, *str, ret);
		display_f(fd, str + 1, ptr, ret);
	}
	else if (*str == '%' && *(str + 1) == '%')
	{
		*ptr += 2;
		putchar_fd(fd, *str, ret);
		display_f(fd, str + 2, ptr, ret);
	}
}
