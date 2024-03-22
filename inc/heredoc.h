/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:28:25 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/22 12:04:50 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include "structure.h"
# include "../src/libft/inc/libft.h"
# include "../src/gnl/get_next_line.h"

int	heredoc(t_rd *rd, t_shell *d);
#endif
