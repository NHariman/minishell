/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_enviorment.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 18:42:42 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/07 18:55:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void    ft_add_variables(t_struct_m *echo)
{
    t_struct_t trim;

	set_value_trim(&trim);
    trim.s_str = ft_strdup(echo->str);
    free(echo->str);
    while(trim.s_str[trim.begin] && trim.s_str[trim.begin] != '\n')
    {
        trim.begin++;
    }
    echo->str = ft_strdup(trim.s_str);
    free(trim.s_str);
}
