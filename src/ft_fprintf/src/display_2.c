/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:42:45 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/23 14:26:14 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_fprintf.h"

void	putnbr_u_fd(int fd, unsigned int nb, int *ptr)
{
	if (*ptr == -1)
		return ;
	if (nb > 9)
	{
		putnbr_u_fd(fd, nb / 10, ptr);
		putnbr_u_fd(fd, nb % 10, ptr);
	}
	if (nb < 10)
		putchar_fd(fd, nb + 48, ptr);
}

void	puthexa_fd(int fd, unsigned int nb, int *ptr, char *base)
{
	if (*ptr == -1)
		return ;
	if (nb >= 16)
	{
		puthexa_fd(fd, nb / 16, ptr, base);
		puthexa_fd(fd, nb % 16, ptr, base);
	}
	if (nb < 16)
		putchar_fd(fd, base[nb], ptr);
}
