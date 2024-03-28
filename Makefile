NAME			=	minishell
BIN				=	bin
BUILTIN			=	cd env echo error exit export export_2 export_3 pwd unset update_cwd utils
EXECUTION		=	child_execution close_pipe env_list_to_tab exec_builtin ft_exit_code ft_set_status\
					is_dir parent_execution set_path redirection start_execution
GNL				=	get_next_line get_next_line_utils
HEREDOC			=	heredoc
INITIALIZATION	=	init_builtin init_env init_history init_lexer init_parser init_pid init_pipe init_prompt \
					init_shell init_shlvl init_minimal_env
LEXER			=	check_syntax check_syntax_utils lexer_utils_0 lexer_utils_1 lexer list_utils
PARSER			=	expand expand_utils parser_utils parser tilde
UTILS			=	alloc_len exit_shell fd ft_exitstatus free free_table main print_error signal
SRCS			=	$(addsuffix .c, $(addprefix src/builtin/, $(BUILTIN))) \
					$(addsuffix .c, $(addprefix src/debug/, $(DEBUG))) \
					$(addsuffix .c, $(addprefix src/execution/, $(EXECUTION))) \
					$(addsuffix .c, $(addprefix src/gnl/, $(GNL))) \
					$(addsuffix .c, $(addprefix src/heredoc/, $(HEREDOC))) \
					$(addsuffix .c, $(addprefix src/initialization/, $(INITIALIZATION))) \
					$(addsuffix .c, $(addprefix src/lexer/, $(LEXER))) \
					$(addsuffix .c, $(addprefix src/parser/, $(PARSER))) \
					$(addsuffix .c, $(addprefix src/utils/, $(UTILS)))
INC				=			-Iinc -I/Users/$(USER)/.brew/opt/readline/include
LIB_DIR			=			-Lsrc/libft -Lsrc/ft_fprintf -L/Users/$(USER)/.brew/opt/readline/lib
LIB				=			-lreadline -lhistory -lft -lftfprintf
CFLAGS			=			-Wall -Wextra -Werror
OBJS			=			$(addprefix $(BIN)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	make -C src/libft
	make -C src/ft_fprintf
	cc $(CFLAGS) $(OBJS) $(LIB_DIR) $(LIB) -o $(NAME)

$(BIN)/%.o: src/tokens/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/builtin/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/debug/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/execution/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/initialization/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/gnl/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/lexer/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/heredoc/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/parser/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(BIN)/%.o: src/readline/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@ $(IREADLINE)

$(BIN)/%.o: src/signal/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@ $(IREADLINE)

$(BIN)/%.o: src/utils/%.c | $(BIN)
	cc $(CFLAGS) $(INC) -c $< -o $@ $(IREADLINE)

$(BIN):
	mkdir -p $(BIN)

clean:
	make -C src/libft clean
	make -C src/ft_fprintf clean
	@if [ -e $(BIN) ]; then \
			echo "__Cleaning objects"; \
			echo "=> rm -rf $(BIN)"; \
			/bin/rm -rf $(BIN); \
	fi

fclean: clean
	make -C src/libft fclean
	make -C src/ft_fprintf fclean
	@if [ -e $(NAME) ]; then \
			echo "__Cleaning executable"; \
			echo "=> rm -f $(NAME)"; \
			/bin/rm -f $(NAME); \
	fi
	rm -f .input
	rm -f .minishell

re: fclean all

.PHONY: all clean fclean re
