/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:18:58 by gde-win           #+#    #+#             */
/*   Updated: 2024/03/22 08:44:51 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H
# define DQUOTE 34
# define E_SHLVL1 "minishell: warning: shell level ("
# define E_SHLVL2 ") too high, resetting to 1"
# define ECWD1 "cd: error retrieving current directory: getcwd: "
# define ECWD2 "cannot access parent directories: "
# define ENV 1
# define EXPORT 2
# define INT64MAX "9223372036854775807"
# define INT64MIN "9223372036854775808"
# define HD_PROMPT "> "
# define HERE_DOC "<<"
# define INPUT_REDIRECTION "<"
# define MAX_VAL "9223372036854775807"
# define METACHAR "<>|"
# define MIN_VAL "9223372036854775808"
# define OUTPUT_APPEND_REDIRECTION ">>"
# define OUTPUT_REDIRECTION ">"
# define PIPE "|"
# define PROMPT "minishell-1.0$ "
# define READ 0
# define SQUOTE 39
# define STDERR 2
# define WHITESPACES "\t\n\v\f\r "
# define WRITE 1
#endif
