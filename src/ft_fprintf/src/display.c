/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:08:25 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/23 14:26:04 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fprintf.h"

void	putchar_fd(int fd, char c, int *ptr)
{
	if (write(fd, &c, 1) == -1)
		*ptr = -1;
	else
		*ptr += 1;
}

void	putstr_fd(int fd, char *str, int *ptr)
{
	int	i;

	if (str == NULL)
	{
		if (write(fd, "(null)", 6) == -1)
			*ptr = -1;
		else
			*ptr += 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) == -1)
		{
			*ptr = -1;
			return ;
		}
		*ptr += 1;
		i++;
	}
}

void	putptr_fd(int fd, void *ptr, int *ptr_i)
{
	size_t	adr;

	adr = (size_t) ptr;
	putstr_fd(fd, "0x", ptr_i);
	if (*ptr_i == -1)
		return ;
	put_hexa_fd(fd, adr, ptr_i, "0123456789abcdef");
	if (*ptr_i == -1)
		return ;
}

void	put_hexa_fd(int fd, size_t nb, int *ptr, char *base)
{
	if (*ptr == -1)
		return ;
	if (nb >= 16)
	{
		put_hexa_fd(fd, nb / 16, ptr, base);
		put_hexa_fd(fd, nb % 16, ptr, base);
	}
	if (nb < 16)
		putchar_fd(fd, base[nb], ptr);
}

void	putnbr_fd(int fd, long nb, int *ptr)
{
	if (*ptr == -1)
		return ;
	if (nb < 0)
	{
		putchar_fd(fd, '-', ptr);
		nb *= -1;
	}
	if (nb > 9)
	{
		putnbr_fd(fd, nb / 10, ptr);
		putnbr_fd(fd, nb % 10, ptr);
	}
	if (nb >= 0 && nb < 10)
		putchar_fd(fd, nb + 48, ptr);
}
