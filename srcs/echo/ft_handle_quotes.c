/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_handle_quotes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 19:06:28 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/07 19:34:59 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

void        ft_handle_quotes(t_struct_m *echo)
{
    t_struct_q han;

	set_value_han(&han);
    han.s_str = ft_strdup(echo->str);
    free(echo->str);
    while(han.s_str[han.begin] && han.s_str[han.begin] != '\n')
    {
        han.begin++;
    }
    echo->str = ft_strdup(han.s_str);
    free(han.s_str);
}
