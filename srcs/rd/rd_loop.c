/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/19 14:06:15 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int			rd_loop(t_struct_rd *rd, t_shell *shell)
{
    int     error;
    t_struct_m	*echo;
    
    echo = ft_calloc(1, sizeof(t_struct_m));
    rd->i = 0;
    rd->file = ft_strdup("");
    while (rd->str[rd->i] && rd->str[rd->i] != '\n' && error == 0)
    {
        set_value_rd(rd);
        error = rd_check_error_rd(rd);//get the rd
        if (error != 0)
            return (error);
        cut_string_shell(rd, shell);//have the file name, don;t forget to trim the empty lines
        while (rd->str[rd->i] == ' ')
            rd->i++;
        if (rd->str[rd->i] != '>' && rd->str[rd->i] != '\0' && rd->str[rd->i] != '\n' && rd->txt == 0)
        {
            if (rd->str != NULL)
            {
                rd->cache = ft_strjoin(rd->string, " ");
                free(rd->string);
                rd->string = ft_strdup(rd->cache);
                free(rd->cache);
            }
            // printf("len == [%i] c == [%c][%i]\n", rd->len, rd->str[rd->i], rd->i);
            rd->len = ft_len_string_rd(rd);
            ft_echo_string_rd(rd, shell);
            rd->tmp = ft_strjoin(rd->string, rd->cache);
            free(rd->string);
            free(rd->cache);
            rd->string = ft_strdup(rd->tmp);
            free(rd->tmp);
        }
        else if (rd->str[rd->i] != '>' && rd->str[rd->i] != '\0' && rd->str[rd->i] != '\n' && rd->txt == 1)
        {
            rd->len = ft_len_string_rd(rd);
        }
        ft_printf("file == [%s]", rd->file);
        //rd->str[rd->i] != '>' && rd->str[rd->i] != '\0' && rd->str[rd->i] != '\n'
        //string add
        //if rd->str[rd->i] == '\0' && rd->str[rd->i] == '\n'
        free(rd->file);
    }
    ft_printf("string == [%s]\n", rd->string);
    return (error);
}
