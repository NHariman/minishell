/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 18:06:37 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
	first check for >

	if file is there, chck if its ther,e then jsut put the info in there
	//if file is not there, create and then ut it in

	go to the back until you see a > if there is a " " then put that on and move
	until you see another one that hasn't gotten a /, if you find a , that doens't have double or
	single on, then you can save this as the rdi->i and use begin, and then the first string
	you get until empty line or '\0' is the file name, if there is no '0'then the rest is a string you put in
	str. now you move along the logic

	frist string is file
	second string is word until <
	save this string and put it through the funnel
	keep saving the tring accordingly
	> means after eah other
	>> means add a \n and then the word

	>> means you add the whole str that is created, fi ther eis already one, then do it under

	echo hello  >> file1 pwd >> file2 hello >>file3
	if echo, then the str are str
	else, for example pwd, you only hav the input pwd

	action txt > file txt

    error

    3 = bash: syntax error near unexpected token `>' 
    4 = bash: syntax error near unexpected token `>>'
*/

int         rd_check_error_rd(t_struct_rd *rd)
{
    if (rd->str[rd->i] == '>')
        rd->dir++;
    rd->i++;
    if (rd->str[rd->i] == '>')
        rd->dir++;
    rd->i++;
    if (rd->str[rd->i] == '>' && rd->str[rd->i + 1] == '>')
    {
        error = 4
        return (4);
    }
    else if (rd->str[rd->i] == '>')
    {
        error = 3
        return (3);
    }
    return (0);
}

char        *rd_save_echo(t_struct_rd *rd)
{
    int     len;
    int     i;
    char    *str;

    len = rd->i;
    i = 0;
    while (rd->str[len] == '\n' || rd->str[len] || rd->str[len] == '>')
        len++;
    str = (char *)malloc((len + 1) * sizeof(char));
    while (rd->i <= len)
    {
        str[i] = rd->str[rd->i];
        i++;
        rd->i++;
    }
    str[i] = '\0';
}

// char        *make_file(t_struct_rd *rd)
// {
//     int     fd;
    
//     fd = open(rd->file, O_EXCL | O_CREAT, 0666);
//     if (fd < 0)
//         return (0);
//     return (0);
// }

// char        *rd_input_file(t_struct_rd *rd)
// {
//     int     fd;
    
//     fd = open(rd->file, O_EXCL | O_CREAT, 0666);
//     if (fd < 0)
//         return (0);
//     if (rd->dir == 1)
//     {

//     }
//     else if (rd->dir == 2)
//     {
        
//     }
//     return (0);
// }

int			rd_loop(t_struct_rd *rd, t_shell *shell)
{
    char    *cache;
    int     error;
    t_struct_m	*echo;
    
    echo = ft_calloc(1, sizeof(t_struct_m));
    rd->i = 0;
    rd->file = ft_strdup("");
    while (rd->str[rd->i] || rd->str[rd->i] == '\n')
    {
        rd->dir = 0;
        error = rd_check_error_rd(rd);
        if (error > 0)
            return (error);   
        set_value_rd(rd);
        cache = cut_string_shell(rd->str, rd, shell);
        free(rd->file);
        rd->file = ft_strdup(echo_main(cache, echo, shell));
        free(cache);
        while (rd->str[rd->i] == ' ')
            rd->i++;
        else if (rd->str[rd->i] == '>')
        {
            ft_printf("[%s], ", rd->file);
            error = make_file(rd);
        }
        else
        {
            cache = rd_save_echo(rd);
            rd->cache = ft_strdup(echo_main(cache, echo, shell));
            free(cache);
            cache = ft_strjoin(rd->string, rd->cache);
            free(rd->string);
            free(rd->cache);
            rd->string = ft_strdup(cache);
            if (rd->str[rd->i] == '\n' || rd->str[rd->i])
            {
                error = rd_input_file(rd);
                ft_printf("[%s], ", rd->file);
                ft_printf("[%s]\n", rd->txt);
                return (error);
            }
            else
            {
                ft_printf("[%s], ", rd->file);
                error = make_file(rd);
            }
        }
    }
    return (error);
}

int		start_rd(t_struct_rd *rd, t_shell *shell)
{
	char	*str;
	int		error;

	rd->i = 0;
	error = 0;
	// cut_string_shell(rd->s_str, rd, shell);//use to get the string out
    rd->string = ft_strdup(" ");
    error = ft_check_rd(rd, shell);
	else if (error == 0)
		error = rd_loop(rd, shell);
	return (error);
}

int		rd_main(char *str, t_shell *shell)
{
    t_struct_rd	*rd;
	int		error;

    rd = calloc(1, sizeof(t_struct_rd));
	set_value_rd(&rd);
    rd.i = 0;
	rd.str = ft_strdup(str);
	error = start_rd(&rd, shell);
    free(rd); 
	return (error);
}
