/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:09:35 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/28 17:53:06 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//get_next_line.c
char	*get_next_line(int fd);
char	*get_first_line(char *buffer, char *rest, size_t i, size_t j);
char	*_join(char *head, char *body);
char	*_read(char *join, char *line, int i, int fd);
//get_next_line_utils.c
void	*_calloc(size_t count, size_t size);
void	_bzero(void *s, size_t n);
char	*_strjoin(char const *s1, char const *s2);
size_t	_strlen(const char *s);
char	*_strchr(const char *s, int c);

#endif
