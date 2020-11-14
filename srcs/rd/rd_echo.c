/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/12 19:36:41 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
	first check for >

	if file is there, chck if its ther,e then jsut put the info in there
	//if file is not there, create and then ut it in
*/

void        rd_get_str_end(t_struct_rd *rd, t_shell *shell)
{
    int     i;
    char    *s1;
    char    *s2;

    s1 = ft_strdup("");
    i = rd->i;
    while (rd->s_str[i] || rd->s_str[i]);
        i++;
    s2 = (char *)malloc((i + 1) * sizeof(char));
    i = 0;
    while (rd->s_str[rd->i] || rd->s_str[rd->i])
    {
       s2[i] = rd->s_str[rd->i];
        rd->i++;
    }
    s2[i] = '\0';
    rd->input = ft_strjoin(s1, s2);
    free(s1);
    free(s2);
}

void		rd_echo_first_file(t_struct_rd *rd, t_shell *shell)
{
    int     begin;
    char    *file1;
    char    *txt;
    int     i;

	while (rd->s_str[rd->i] != '>')
        rd->i--;
    begin = rd->i;
    rd->i++;
    while (rd->s_str[rd->i] != ' ')
        rd->i++;
    i = rd->i;
    while (rd->s_str[i] != ' ')
        i++;
    i = 0;
    file1 = (char *)malloc((i + 1) * sizeof(char));
    while (rd->s_str[rd->i] != ' ')
    {
        file1[i] = rd->s_str[rd->i]
        i++;
        rd->i++;
    }
    file[i] = '\0';
    rd->file[0] = ft_strdup(file1);
    free(file1);
    while (rd->s_str[rd->i] != ' ');
        rd->i++;
    if (rd->s_str[rd->i] != '\n' || rd->s_str[rd->i] != '\0')
        rd_get_str_end(rd, shell);
}

static int  rd_size_file(char *str)
{
    int single;
    int doubble;
    int i;
    int len;

    single = 0;
    doubble = 0;
    i = 0;
    len = 0;
    while (str[i])
    {
        if (str[i] == '>' && (single == 0 || doubble == 0))
        {
            len++;
            while (str[i] == '>')
                i++;
        }
        else if (str[i] == '\"' && single == 0 && doubble == 0)
            doubble = 1;
        else if (str[i] == '\"' && single == 0 && doubble == 1)
            doubble = 0;
        else if (str[i] == '\'' && single == 0 && doubble == 0)
            single = 1;
        else if (str[i] == '\'' && single == 1 && doubble == 0)
            doubble = 0;
        i++;
    }
    return (len);
}

void		rd_echo(t_struct_rd *rd, t_shell *shell)
{
    int     len;

	rd->i = ft_strlen(rd->s_str);
    len = rd_size_file(rd->s_str)
    rd->file = (char **)malloc((len + 1) * sizeof(char));
    rd->file[len + 1] = NULL;
	rd_echo_first_file(rd, shell);
    
}
