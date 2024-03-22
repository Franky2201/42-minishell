NAME	=	libft.a
BIN		=	bin
INC		=	-I inc
SRCS	=	src/ft_error_va.c src/ft_isdigit.c src/ft_memcpy.c src/ft_split.c \
        	src/ft_strlen.c src/ft_tolower.c src/ft_atoi.c src/ft_isprint.c src/ft_memmove.c \
			src/ft_strchr.c src/ft_strmapi.c src/ft_toupper.c src/ft_bzero.c src/ft_itoa.c src/ft_longest.c\
			src/ft_memset.c src/ft_strdup.c src/ft_strncmp.c src/ft_calloc.c src/ft_putchar_fd.c src/ft_free_tab.c\
			src/ft_striteri.c src/ft_strnstr.c src/ft_isalnum.c src/ft_putendl_fd.c src/ft_strjoin.c \
			src/ft_strrchr.c src/ft_isalpha.c src/ft_memchr.c src/ft_putnbr_fd.c src/ft_strlcat.c src/ft_tabsize.c\
			src/ft_strtrim.c src/ft_isascii.c src/ft_memcmp.c src/ft_putstr_fd.c src/ft_substr_len.c\
			src/ft_strlcpy.c src/ft_substr.c src/ft_lstadd_back.c src/ft_lstadd_front.c src/ft_lstclear.c \
			src/ft_lstdelone.c src/ft_lstfirst.c src/ft_lstiter.c src/ft_lstinsert.c src/ft_lstlast.c src/ft_lstmap.c src/ft_lstnew.c src/ft_lstsize.c
CFLAGS	=	-Wall -Wextra -Werror -g
ASAN	=	-fsanitize=address
OBJS	=	$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))
FLAGS_FILE = $(BIN)/.flags
EXISTING_FLAGS := $(shell cat $(FLAGS_FILE) 2>/dev/null)

GREEN		= \033[0;32m
RED			= \033[0;31m
LIGHTBLUE	= \033[1;34m
NC			= \033[0m

all: check_flags $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

asan: CFLAGS += $(ASAN)
asan: check_flags all

check_flags: | $(BIN)
	@if [ "$(CFLAGS)" != "$(EXISTING_FLAGS)" ]; then \
		rm -f $(OBJS) $(NAME); \
	fi
	@echo "$(CFLAGS)" > $(FLAGS_FILE)

$(BIN)/%.o: src/%.c | $(BIN)
	@echo "$(CFLAGS)" > $(FLAGS_FILE)
		cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN):
	mkdir -p $(BIN)

clean:
	@if [ -e $(BIN) ]; then \
		echo "$(GREEN)__Cleaning objects$(NC)"; \
		echo "$(LIGHTBLUE)=> rm -rf $(BIN)$(NC)"; \
		/bin/rm -rf $(BIN); \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		echo "$(GREEN)__Cleaning library$(NC)"; \
		echo "$(LIGHTBLUE)=> rm -f $(NAME)$(NC)"; \
		/bin/rm -f $(NAME); \
	fi

re: fclean all

.PHONY: all clean fclean re
