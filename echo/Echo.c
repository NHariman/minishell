/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:31:50 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 18:44:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include ../srcs/minishell.h

int     check_n(int end, char* str)
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

int     lenght_n(int end, char* str)
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
        return (i);
    return (0);
}

/* if there is only words in the string */
char    *no_str(int i, char* str, char* cache)
{
    int     y   =   i;
    int     len   =   0;
    char*   tmp =   NULL;

    while (str[i] != '\"' || str[i] != '\'' || str[i])
    {
        len++
        i++;
    }
    i = y;
    tmp = (char *)malloc((len + 1) * sizeof(char));
    y = 0;
    while (str[i] != '\"' || str[i] != '\'')
    {
        tmp[y] = str[i];
        y++;
        i++
    }
    cache = ft_strjoin(cache, tmp);
    free(tmp);
    return (cache);
}

int     no_str_i(int i, char* str)
{
    while (str[i] || str[i] != '\'' || str[i] != '\"')
    {
        i++;
    }
    return (i);
}

char*   see_dollar(char* str, int i)
{

}

/* if we find a " check for commands*/

char*   str_double(int i, char* str, char cache)
{
    int     y   =   i;
    size_t    len   =   0;
    char*   tmp =  NULL;

    i++;
    while (str[i] != "\"")
        i++;
    i = y;
    while (str[i] != "\"")
    {
        if (str[i] != '$')
        {
            ft_strjoin(cache, &str[i]);
            i++;
        }
        else if
        {
            tmp = see_dollar(str, i);
            cache = ft_strjoin(cache, tmp);
            free(tmp);
        }
    }
    /* infinite loop
    chekc for normal
    then check for dollar and add that to the cache
    then */
}

/* if we find a '*/

void    echo_main(char* str)
{
    /*as soon as this comes in, the string i have has echo cut off from
    */
    t_struct_m *Echo;

    Echo = ft_calloc(1, sizeof(t_struct_m));
    char*   str = "hello";

    end = check_n(end, str);
    if (end == 1)
        i = lenght_n(str); /*now it knows when -n has ended */
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        /*check for double " " does the same as in single, but it inputs the commands*/
        if (str[i] != '\"' || str[i] != '\'')
        {
            cache = no_str(i, str, cache);
            i = no_str_i(i, str);
        }
        else if (tr[i] == '\"')
        {
            cache = str_double(i, str, cache);
            i = str_double_i(i, str);
        }
        else if (str[i] == '\'')
        {
            cache = str_single(i, str, cache);
            i = str_single_i(i, str);
        }
    }
}

/*
check for echo
check for pipe 
save string
do pipe
if pipe failed write string
*/