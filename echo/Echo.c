/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 16:31:50 by ybakker       #+#    #+#                 */
/*   Updated: 2020/10/31 21:38:37 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include ../srcs/minishell.h

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

char*   see_dollar(char* str, t_struct_m *Echo, char c)
{
    int     len = 0;
    int     y = Echo->i;
    int     a = 0;
    char*   tmp = NULL;
    Echo->i++;/*adds one to have furder from the $ sign */
    while (str[Echo->i] != c || str[Echo->i])/*if ast this function, then you knwo the end of the $ command */
    {
        len++;
        Echo->i++;
    }
    tmp = (char *)malloc((len + 1) * sizeof(char));
    while (len >= 0)
    {
        tmp[a] = str[y];
        y++;
        a++;
    }
    tmp = check_variable(tmp);
    return (tmp);
    /* check the command */
    /* if command is failed then return the tmp
    if success, return what the command needs to do*/
}

/* if we find a " check for commands*/

char*   str_double(t_struct_m *Echo)
{
    int         y   =   Echo->i;
    size_t      len   =   0;
    char*       tmp =  NULL;

    Echo->i++;
    while (str[Echo->i] != '\"')
    {
        if (str[Echo->i] == '\0')
            while (1);
        Echo->i++;
    }
    Echo->i = y;
    while (str[Echo->i] != '\"')
    {
        while (str[Echo->i] != '$' || str[Echo->i] != '\"')
        {
            Echo->cache = ft_strjoin(Echo->cache, &str[i]);/*save everything until $*/
            Echo->i++;
        }
        if (str[Echo->i] == '$' || str[Echo->i] != '\"')
        {
            tmp = see_dollar(Echo, '\"');/*make sure to add the i so it can be used after */
            Echo->cache = ft_strjoin(Echo->cache, tmp);
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

/*
check for echo
check for pipe 
save string
do pipe
if pipe failed write string
*/