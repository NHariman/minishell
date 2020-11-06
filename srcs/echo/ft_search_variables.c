/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_search_variables.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 20:56:01 by anonymous     #+#    #+#                 */
/*   Updated: 2020/11/06 20:56:01 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

void    ft_search_variable(t_struct_m *echo, char str, int start)
{
	// \ before $, then is shouldn't be removed
	int		b;

	b = start;
	b--;
	if (echo->str[b] == '\\')
	{
		echo->t_tmp = ft_strdup(str);
		free(str);
		return ;
	}
	echo->t_tmp = ft_pwd();
}