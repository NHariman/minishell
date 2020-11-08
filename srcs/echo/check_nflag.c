/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_nflag.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 12:54:04 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/08 12:59:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

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
		if (echo->str[echo->i] == 'n')
			echo->i = skip_character(echo->str, echo->i, 'n');
		printf("c ==[%c] i == [%i]\n", echo->str[echo->i], echo->i);
		if (echo->str[echo->i] == ' ')
		{
			echo->n = 1;
			echo->i = skip_character(echo->str, echo->i, ' ');
		}
		printf("c ==[%c] i == [%i]\n", echo->str[echo->i], echo->i);
		if (echo->str[echo->i] == '\n' || echo->str[echo->i] == '\0')
		{
			echo->n = 1;
			return (echo->i);
		}
	}
	return (echo->i);
}
