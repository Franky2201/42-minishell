/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:18:37 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/21 22:48:22 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "../src/ft_fprintf/inc/ft_fprintf.h"
# include "../src/libft/inc/libft.h"
# include "constant.h"
# include "structure.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

int		dup_value(char *str, int option, t_env *var);
int		builtin_error(char **argv);
int		cd(t_builtin *d);
int		echo(t_builtin *d);
int		env(t_builtin *d);
int		__exit(t_builtin *d);
void	init_var(t_env *old, t_env *new);
void	d_export(t_list *lst);
int		_export(t_builtin *d);
int		display_env(t_list *lst);
int		pwd(t_builtin *d);
int		unset(t_builtin *d);
int		lst_iter(t_list *head, t_list *node, t_env **n, char *s);
char	*expand_var(char *varname, t_list *env);
#endif
