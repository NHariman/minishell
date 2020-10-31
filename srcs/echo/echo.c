/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 21:21:07 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 21:50:36 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include ../minishell.h

int     check_n(char* str)
{
    int i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-')
        i++
    else
        return(0);
    if (str[i] == 'n')
    {
        while (str[i] == 'n')
            i++;
    }
    if (str[i] == ' ')
        return (1);
    return (0);
}

void    no_str(t_struct_m *Echo, char* str)
{
    int     y   =   Echo->i;
    int     len =   0;
    char*   tmp =   NULL;

    while (str[Echo->i] != '\"' || str[Echo->i] != '\'' || str[Echo->i])
    {
        len++;
        Echo->i++;
    }
    Echo->i = y;
    tmp = (char *)malloc((len + 1) * sizeof(char));
    y = 0;
    while (str[Echo->i] != '\"' || str[Echo->i] != '\'')
    {
        tmp[y] = str[Echo->i];
        y++;
        Echo->i++;
    }
    Echo->cache = ft_strjoin(Echo->cache, tmp);
    free(tmp);
}

char       *echo_main(char  *str)
{
    t_struct_m *Echo;

    Echo = ft_calloc(1, sizeof(t_struct_m));
    Echo->end = check_n(str);
    if (Echo->end == 1)
        Echo->i = lenght_n(Echo->end, str); /*now it knows when -n has ended */
    while (str[Echo->i] == ' ')
        Echo->i++;
    while(str[Echo->i])
    {
        if (str[Echo->i] != '\"' || str[Echo->i] != '\'')
            no_str(Echo, str);
    }
    return (Echo->cach);
}

