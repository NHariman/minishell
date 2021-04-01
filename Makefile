# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2021/04/01 14:56:10 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc
# COMPILE = clang
FLAGS = -Wall -Werror -Wextra
MINISHELL =     main.c \
				srcs/main/gnl_utils.c \
				srcs/main/get_next_line_sig.c \
				srcs/main/main_parser.c \
				srcs/main/gen_functions.c \
				srcs/main/ft_argv.c \
				srcs/main/ft_prompts.c \
				srcs/main/dollar_sign.c \
				srcs/main/ft_skip_redirections.c \
				srcs/quotations/ft_skip_quotes.c \
				srcs/quotations/quotation_handler.c \
				srcs/quotations/check_quotes.c \
				srcs/quotations/quotations_parser.c \
				srcs/quotations/no_quotations_parser.c \
				srcs/subparsers/ft_get_rdin.c \
				srcs/subparsers/ft_invalid_line.c \
				srcs/subparsers/ft_make_prompts.c \
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

ECHO =          srcs/rd_new/check_redirect.c \
				srcs/rd_new/rd_fill_file.c \
				srcs/rd_new/rd_get_file_name.c \
				srcs/rd_new/rd_get_nb.c \
				srcs/rd_new/rd_loop.c \
				srcs/rd_new/rd_main.c \
				srcs/syntax/syntax_check.c\
				srcs/syntax/check_end.c \
				srcs/syntax/check_red.c \
				srcs/syntax/rd_syntax_error_add.c \
				srcs/signals/ft_signals.c


OMINISHELL = 	$(MINISHELL:.c=.o)

OECHO =			$(ECHO:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OMINISHELL) $(OECHO) srcs/libft/libft.a
	@$(COMPILE) $(OMINISHELL) $(OECHO) -g srcs/libft/libft.a -o $@
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

test: re
	./minishell

leaks: fclean $(OMINISHELL) $(OECHO) srcs/libft/libft.a
	@$(COMPILE) $(OMINISHELL) $(OECHO) srcs/libft/libft.a -o minishell
	./minishell