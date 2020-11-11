/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_handle_quotes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 19:06:28 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/11 11:15:31 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

void		ft_handle_quotes(t_struct_m *echo)
{
	t_struct_q han;

	set_value_han(&han);
	han.s_str = ft_strdup(echo->str);
	han.i = echo->i;
	free(echo->str);
	printf("i  == [%i]\n", han.i);
	printf("c  == [%c]\n", han.s_str[han.i]);
	while (han.s_str[han.i] && han.s_str[han.i] != '\n')
	{
		if (han.s_str[han.i] == '\"')
			echo_double_str(&han);
		else if (han.s_str[han.i] == '\'')
			echo_single_str(&han);
		// else
		// 	echo_no_str(&han);
	}
	echo->str = ft_strdup(han.s_store);
	free(han.s_str);
	free(han.s_store);
	echo->i = han.i;
}
