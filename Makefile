# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/11/05 14:54:50 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

MINISHELL =		main.c \
				srcs/main/get_next_line.c \
				srcs/main/gen_parsers.c \
				srcs/cd/ft_cd.c \
				srcs/pwd/ft_pwd.c

ECHO =			srcs/echo/echo.c

OMINISHELL = 	$(MINISHELL:.c=.o)

OECHO =			$(ECHO:.c=.o)


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
