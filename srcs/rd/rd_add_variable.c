/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_add_variable.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 12:13:18 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 12:13:40 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	ft_add_variables_double(t_struct_m *echo)
{
	t_struct_tr	trim;

	set_value_trim(&trim);
	trim.flag = 0;
	trim.s_str = ft_strdup(echo->str);
	trim.begin = echo->i;
	free(echo->str);
	if (trim.s_str[trim.begin - 1] == ' ' && trim.begin != 0)
		trim.empty = 1;
	ft_split_variable(&trim);
	echo->str = ft_strdup(trim.s_str);
	free(trim.s_str);
}
