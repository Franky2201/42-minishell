# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-win <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 16:12:50 by gde-win           #+#    #+#              #
#    Updated: 2024/02/13 20:32:27 by gde-win          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			minishell

CC :=			cc

CFLAGS :=		-Wall -Wextra -Werror -I. -fsanitize=address -g

LREADLINE:=		-lreadline -lhistory -L/Users/$(USER)/homebrew/opt/readline/lib

IREADLINE:=		-I/Users/$(USER)/homebrew/opt/readline/include

FUNCTIONS :=	main.c \
				clean_quotes.c \
				lexer.c \
				lexer_utils_0.c \
				lexer_utils_1.c \
				list_utils.c

SRCS :=			$(FUNCTIONS)

OBJS :=			$(SRCS:.c=.o)

INCLUDE :=		lexer.h

LIBFT :=		libft

all:			$(LIBFT) $(OBJS) $(NAME)

$(LIBFT):
					@make -C $@

%.o:			%.c
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
