# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/11/15 13:40:21 by ybakker       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc
# COMPILE = clang

FLAGS = -Wall -Werror -Wextra

MINISHELL =		main.c \
				srcs/main/get_next_line.c \
				srcs/main/echo_parser.c \
				srcs/main/gen_functions.c \
				srcs/main/quotation_handler.c \
				srcs/main/main_parser.c \
				srcs/cd/ft_cd.c \
				srcs/pwd/ft_pwd.c

ECHO =			srcs/echo/check_nflag.c\
				srcs/echo/echo.c\
				srcs/echo/ft_add_enviorment.c\
				srcs/echo/ft_clean_echo.c\
				srcs/echo/ft_get_variable.c\
				srcs/rd/cutstring_rd.c\
				srcs/rd/re_direct.c

# RD =			srcs/rd/cutstring_rd.c\
# 				srcs/rd/re_direct.c

OMINISHELL 	= 	$(MINISHELL:.c=.o)

OECHO		=	$(ECHO:.c=.o)
# ORD			=	$(RD:.c=.o)


NAME = minishell

all: $(NAME)

$(NAME): $(OMINISHELL) $(OECHO) srcs/libft/libft.a
	@$(COMPILE) $(OMINISHELL) $(OECHO) -g -fsanitize=address srcs/libft/libft.a -o $@

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
