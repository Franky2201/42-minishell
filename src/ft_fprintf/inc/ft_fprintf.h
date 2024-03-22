/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:10:54 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/18 11:21:03 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//ft_fprintf.c
int		ft_fprintf(int fd, const char *f, ...);
int		is_conv(char c);
void	display_f(int fd, char *str, char **ptr, int *ret);
void	display_arg(int fd, char c, va_list arg, int *ptr);
//display.c
void	putchar_fd(int fd, char c, int *ptr);
void	putstr_fd(int fd, char *str, int *ptr);
void	putptr_fd(int fd, void *ptr, int *ptr_i);
void	put_hexa_fd(int fd, size_t nb, int *ptr, char *base);
void	putnbr_fd(int fd, long nb, int *ptr);
//display_2.c
void	putnbr_u_fd(int fd, unsigned int nb, int *ptr);
void	puthexa_fd(int fd, unsigned int nb, int *ptr, char *base);
int		check_error(const char *f, va_list arg, int i);
#endif