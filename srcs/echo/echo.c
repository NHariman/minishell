/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/08 17:04:04 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

int		skip_character(char *str, int i, char c)
{
	while (str[i] == c && (str[i]))
	{
		i++;
	}
	return (i);
}

char       *echo_main(char  *str, t_struct_m *echo)
{
	set_value_echo(echo);
	echo->str = ft_strdup(str);
	free(str);
	if (echo->str[0] == '\n')
		return (echo->str);
	ft_printf("input == [%s]\n", echo->str);
	ft_add_variables(echo);
	ft_printf("varia == [%s]\n", echo->str);
	ft_empty_lines(echo);
	ft_printf("empty == [%s]\n", echo->str);
	echo->i = check_flag_n(echo);
	printf("-n == [%i]\n", echo->n);
	ft_handle_quotes(echo);
	printf("quote == [%s]\n", echo->str);
	if (echo->n == 0)
	{
		echo->cache = ft_strjoin(echo->str, "\n");
		free(echo->str);
		echo->str = ft_strdup(echo->cache);
	}
	printf("end   == [%s]\n", echo->str);
	return (echo->str);
}
