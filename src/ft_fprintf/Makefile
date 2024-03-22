NAME	=	libftfprintf.a
BIN		=	bin
SRCS	=	src/display.c src/display_2.c src/ft_fprintf.c
INC		=	-I inc
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