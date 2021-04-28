# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2021/04/28 18:06:21 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc
# COMPILE = clang

FLAGS = -Wall -Werror -Wextra

MINISHELL =     main.c \
                srcs/prompts/gnl_utils.c \
                srcs/prompts/get_next_line_sig.c \
                srcs/prompts/wordparser.c \
                srcs/prompts/ft_argv_env.c \
                srcs/prompts/ft_argv.c \
                srcs/prompts/ft_prompts.c \
                srcs/prompts/ft_skip_redirections.c \
                srcs/prompts/trim_rd.c \
                srcs/quotations/dollar_sign.c \
                srcs/quotations/ft_skip_quotes.c \
                srcs/quotations/quotation_handler.c \
                srcs/quotations/check_quotes.c \
                srcs/quotations/quotations_parser.c \
                srcs/quotations/no_quotations_parser.c \
                srcs/prompts/ft_get_rdin.c \
                srcs/prompts/ft_make_prompts.c \
                srcs/pipe/ft_pipe_splitter.c \
                srcs/pipe/parent_and_child.c \
                srcs/echo/ft_echo.c \
                srcs/cd/ft_cd.c \
                srcs/pwd/ft_pwd.c \
                srcs/env/env.c \
                srcs/exit/exit.c \
                srcs/free/free.c \
                srcs/execv/ft_execv.c \
                srcs/execv/ft_is_directory.c \
                srcs/execv/ft_make_array.c \
                srcs/execv/ft_preprocessor.c \
                srcs/execv/ft_shlvl.c \
                srcs/export/ft_export.c \
                srcs/export/ft_add_backslash.c \
                srcs/export/ft_format_export.c \
                srcs/export/ft_sort_env.c \
                srcs/export/ft_update_env.c \
                srcs/unset/ft_unset.c 

ECHO =          srcs/rd/check_redirect.c \
				srcs/rd/rd_fill_file.c \
				srcs/rd/rd_get_file_name.c \
				srcs/rd/rd_get_nb.c \
				srcs/rd/rd_loop.c \
				srcs/rd/rd_main.c \
				srcs/rd/rd_open_file.c \
				srcs/syntax/syntax_check.c\
				srcs/syntax/check_end.c \
				srcs/syntax/check_red.c \
				srcs/syntax/rd_syntax_error_add.c \
                srcs/syntax/syntax_error_check.c \
                srcs/syntax/syntax_full_check.c \
                srcs/syntax/syntax_newline.c \
                srcs/syntax/syntax_pipes.c \
				srcs/signals/ft_signals.c


OMINISHELL = 	$(MINISHELL:.c=.o)

OECHO =			$(ECHO:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OMINISHELL) $(OECHO) srcs/libft/libft.a
	@$(COMPILE) $(OMINISHELL) $(OECHO) srcs/libft/libft.a -g -fsanitize=address -o $@
	@chmod 311 ./minishell

srcs/libft/libft.a:
	@cd srcs/libft && $(MAKE)

%.o: %.c srcs/minishell.h srcs/yusha.h srcs/niks.h
	@$(COMPILE) -c $(FLAGS) -o $@ -c $<

clean:
	@$(RM) $(OECHO) $(OMINISHELL)
	@cd srcs/libft && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@cd srcs/libft && $(MAKE) fclean

re: fclean all

leaks: fclean $(OMINISHELL) $(OECHO) srcs/libft/libft.a
	@$(COMPILE) $(OMINISHELL) $(OECHO) srcs/libft/libft.a -o minishell
	./minishell