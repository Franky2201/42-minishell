# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-win <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 16:12:50 by gde-win           #+#    #+#              #
#    Updated: 2024/02/09 18:25:09 by gde-win          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			minishell

CC :=			cc

CFLAGS :=		-Wall -Wextra -Werror -I. -fsanitize=address -g

LREADLINE:=		-lreadline -lhistory -L/Users/$(USER)/homebrew/opt/readline/lib

IREADLINE:=		-I/Users/$(USER)/homebrew/opt/readline/include

FUNCTIONS :=	main.c

SRCS :=			$(FUNCTIONS)

OBJS :=			$(SRCS:.c=.o)

INCLUDE :=		lexer.h

LIBFT :=		libft

all:			$(LIBFT) $(NAME)

$(LIBFT):
					@make -C $@

$(OBJS):		$(SRCS)
					$(CC) $(CFLAGS) $(IREADLINE) -c $< -o $@

$(NAME):		$(OBJS)
					$(CC) $(CFLAGS) $^ -Wl,libft/libft.a $(LREADLINE) -o $@

clean:
					rm -rf $(OBJS)
					@make clean -C $(LIBFT)

fclean:			clean
					rm -rf $(NAME)
					rm -rf libft/libft.a

re:				fclean all

.PHONY:			all clean fclean re libft
