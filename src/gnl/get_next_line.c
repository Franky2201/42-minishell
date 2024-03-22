/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:08:58 by rkersten          #+#    #+#             */
/*   Updated: 2024/02/23 14:21:23 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_join(char *head, char *body)
{
	char	*temp;

	temp = _strjoin(head, body);
	free(head);
	return (temp);
}

char	*get_first_line(char *buffer, char *rest, size_t i, size_t j)
{
	char	*line;

	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = _calloc(i + 2, 1);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	i = -1;
	while (buffer[++i] != '\0' && buffer[i] != '\n')
		line[i] = buffer[i];
	line[i++] = '\n';
	line[i] = '\0';
	while (buffer[i + j] != '\0')
	{
		rest[j] = buffer[i + j];
		j++;
	}
	rest[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	line[BUFFER_SIZE + 1];
	char		*join;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	join = _calloc(1, 1);
	if (*line != '\0')
		join = _join(join, line);
	if (!join)
		return (NULL);
	_bzero(line, BUFFER_SIZE);
	join = _read(join, line, 1, fd);
	if (!join)
		return (NULL);
	if (*join == '\0' && *line == '\0')
	{
		free(join);
		return (NULL);
	}
	return (join);
}

char	*_read(char *join, char *line, int i, int fd)
{
	while (i > 0)
	{
		if (_strchr(join, '\n'))
		{
			join = get_first_line(join, line, 0, 0);
			break ;
		}
		i = read(fd, line, BUFFER_SIZE);
		line[i] = '\0';
		if (i == -1)
		{
			free(join);
			_bzero(line, BUFFER_SIZE);
			return (NULL);
		}
		join = _join(join, line);
		if (!join)
			return (NULL);
		_bzero(line, BUFFER_SIZE);
	}
	return (join);
}
