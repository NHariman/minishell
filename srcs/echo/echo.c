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
	while (str[i] == c && str[i])
	{
		i++;
	}
	return (i);
}

void		check_flag_n(t_struct_m *echo)
{
	echo->i = skip_character(echo->str, echo->i, ' ');
	if (echo->str[echo->i] == '-')
	{
		while (echo->str[echo->i] == '-')
		{
			echo->i++;
			if (echo->str[echo->i] == 'n')
				echo->i++;
			else
				return ;
			if (echo->str[echo->i] == ' ')
				echo->i++;
			else
				return ;
			if (echo->str[echo->i] == '-' && echo->n != 0)
				echo->n = 1;
			else
				return ;
		}
	}
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
	check_flag_n(echo);//doesn't check it correctly
	//give starting position for the next one
	ft_handle_quotes(echo);
	//check flag -n
	//handle quotes
	printf("quote == [%s]\n", echo->str);
	if (echo->n != -1)
	{
		echo->cache = ft_strjoin(echo->str, "\n");
		free(echo->str);
		echo->str = ft_strdup(echo->cache);
	}
	printf("end   == [%s]\n", echo->str);
	return (echo->cache);
}
