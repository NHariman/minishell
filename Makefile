# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nhariman <nhariman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 23:42:48 by nhariman      #+#    #+#                  #
#    Updated: 2020/10/31 13:09:08 by nhariman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc

FLAGS = -Wall -Werror -Wextra

MINISHELL =

OMINISHELL = 	$(MINISHELL:.c=.o)


NAME = minishell

all: $(NAME)

$(NAME): $(OMINISHELL) srcs/libft/libft.a
	@$(COMPILE) $(OMINISHELL) -g -fsanitize=address srcs/libft/libft.a -o $@

srcs/libft/libft.a:
	@cd srcs/libft && $(MAKE)

%.o: %.c srcs/minishell.h
	@$(COMPILE) -c $(FLAGS) -o $@ -c $<

clean:
	@cd srcs/libft && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@cd srcs/libft && $(MAKE) fclean

re: fclean all
