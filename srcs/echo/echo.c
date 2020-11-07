/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/07 19:38:12 by ybakker       ########   odam.nl         */
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

int		check_flag_n(t_struct_m *echo)
{
	echo->s = 0;
	echo->i = skip_character(echo->str, echo->i, ' ');
	while (echo->str[echo->i] == '-')
	{
		echo->s = echo->i;
		echo->i++;
		if (echo->str[echo->i] != 'n')
			return (echo->s);
		else if (echo->str[echo->i] == 'n')
			echo->i = skip_character(echo->str, echo->i, 'n');
		printf("c ==[%c] i == [%i]\n", echo->str[echo->i], echo->i);
		if (echo->str[echo->i] == ' ')
		{
			echo->n = 1;
			echo->i = skip_character(echo->str, echo->i, ' ');
		}
		if (echo->str[echo->i] == '\n' || echo->str[echo->i] == '\0')
		{
			echo->n = 1;
			return (echo->i);
		}
		else
			return (echo->s);
	}
	return (echo->i);
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
	echo->i = check_flag_n(echo);//doesn't check it correctly
	printf("-n == [%i]\n", echo->n);
	printf("i  == [%i]\n", echo->i);
	printf("c  == [%c]\n", echo->str[echo->i]);
	//give starting position for the next one
	ft_handle_quotes(echo);
	//check flag -n
	//handle quotes
	printf("quote == [%s]\n", echo->str);
	if (echo->n == 0)
	{
		echo->cache = ft_strjoin(echo->str, "\n");
		free(echo->str);
		echo->str = ft_strdup(echo->cache);
	}
	printf("end   == [%s]\n", echo->str);
	return (echo->cache);
}
