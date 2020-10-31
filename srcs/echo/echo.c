/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 21:24:59 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include ../minishell.h

void    echo_main(char* str)
{
    /*as soon as this comes in, the string i have has echo cut off from
    */
    t_struct_m *Echo;

    Echo = ft_calloc(1, sizeof(t_struct_m));
    char*   str = "hello";

    Echo->end = check_n(Echo->end, str);
    if (Echo->end == 1)
        Echo->i = lenght_n(Echo->end, str); /*now it knows when -n has ended */
    while (str[Echo->i])
    {
        while (str[Echo->i] == ' ')
            Echo->i++;
        /*check for double " " does the same as in single, but it inputs the commands*/
        if (str[Echo->i] != '\"' || str[Echo->i] != '\'')
            no_str(Echo, str);
        else if (str[Echo->i] == '\"')
            Echo->cache = str_double(Echo);
        else if (str[i] == '\'')
            Echo->cache = str_single(Echo);
    }
}
