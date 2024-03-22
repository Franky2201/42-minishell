/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:17:51 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/20 17:53:48 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_lexer(char *s, t_list **lst)
{
	if (!s)
		return (1);
	*lst = ft_word_segmentation(s, lst);
	if (!lst)
		return (1);
	*lst = ft_token_segmentation(*lst);
	if (!lst)
		return (1);
	if (!ft_check_syntax(*lst))
		return (1);
	return (0);
}
