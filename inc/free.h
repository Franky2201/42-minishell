/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:21:45 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/12 21:24:47 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include "structure.h"
void	free_current_execution(t_shell *d);
void	fd(t_shell *d);
void	free_env_node(void *ptr);
void	free_lexer_node(void *ptr);
void	free_parser_node(void *ptr);
void	free_rd_node(void *ptr);
void	free_table(t_shell *d);
#endif