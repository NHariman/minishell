/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_echo_empty_line.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 21:09:41 by anonymous     #+#    #+#                 */
/*   Updated: 2020/11/06 21:09:41 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// get the empty lines out and make, if there is more than 1 empty line into a single empty line
	//unless its in a single or double quote
	//only 1 single or double can be one, so be warned for that
	//as soon as you see a double or single, loop throug it until you see the next one

// ft_printf("----ERROR START---\n");
// ft_printf("----ERROR END---\n");

#include "../minishell.h"
#include <stdio.h>

typedef struct	s_struct_e
{
    int         begin;
    int         end;
    int         single;
    int         doubble;
    char*       str;
	
}				t_struct_e;

void        set_empty(void)
{
    int     begin = 0;
    int     end = 0;
    int     single = 0;
    int     doubble = 0;
}

static void     ft_empty_line_loop_cut(t_struct_m empty, char *str)
{
    empty->end = empty->begin;
    while (str[empty->end] == ' ')
    {
        empty->end++;
    }
    if (empty->begin < empty->end)
    {
        
    }
}

char*           ft_echo_empty_line(char* str)
{
    t_struct_e *empty;

    set_empty(); 
    while (str[empty->begin] && str[empty->begin] != '\n')
    {
        if (str[empty->begin] == '\"' && empty->single == 0 && empty->doubble == 0)
            empty->doubble = 1;
        else if (str[empty->begin] == '\'' && empty->single == 0 && empty->doubble == 0)
            empty->doubble = 1;
        else if (str[empty->begin] == '\"' && empty->doubble == 1)
            empty->doubble = 0;
        else if (str[empty->begin] == '\'' && empty->single == 1)
            empty->doubble = 0;
        else if (str[empty->begin] == ' ' && empty->single == 0 && empty->doubble == 0)
        {
            ft_empty_line_loop_cut(empty, str);
        }
    }
    return (str);
}