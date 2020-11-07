/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clean_echo.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 18:36:24 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/07 19:14:15 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void        set_value_echo(t_struct_m *echo)
{
    echo->n = 0;
    echo->i = 0;
}

void		set_value_trim(t_struct_t *trim)
{
	trim->begin = 0;
	trim->end = 0;
	trim->single = 0;
	trim->doubble = 0;
}

void		set_value_empty(t_struct_e *empty)
{
	empty->begin = 0;
	empty->end = 0;
	empty->single = 0;
	empty->doubble = 0;
}

void		set_value_han(t_struct_q *han)
{
	han->begin = 0;
	han->end = 0;
	han->single = 0;
	han->doubble = 0;
}
