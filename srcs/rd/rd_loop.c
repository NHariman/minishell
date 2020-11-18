/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 19:23:21 by ybakker       ########   odam.nl         */
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
        // while (rd->str[rd->i] == ' ')
        //     rd->i++;
        printf("c == [%c][%i]\n", rd->str[rd->i], rd->i);
        if (rd->str[rd->i] != '>' && rd->str[rd->i] != '\0' && rd->str[rd->i] != '\n' && rd->txt == 0)
        {
            if (rd->str != NULL)
            {
                rd->cache = ft_strjoin(rd->string, " ");
                free(rd->string);
                rd->string = ft_strdup(rd->cache);
                free(rd->cache);
            }
            printf("string == [%s]\n", rd->string);
            rd->len = ft_len_string_rd(rd);
            printf("len == [%i]\n", rd->len);
            ft_echo_string_rd(rd, shell);
            printf("str == [%s]\n", rd->cache);
            rd->tmp = ft_strjoin(rd->str, rd->cache);
            free(rd->str);
            free(rd->cache);
            rd->str = ft_strdup(rd->tmp);
            free(rd->cache);
        }
        else if (rd->txt == 1)
        {
            rd->len = ft_len_string_rd(rd);
        }
        ft_printf("c == [%c][%i]\n", rd->str[rd->i], rd->i);
        //rd->str[rd->i] != '>' && rd->str[rd->i] != '\0' && rd->str[rd->i] != '\n'
        //string add
        //if rd->str[rd->i] == '\0' && rd->str[rd->i] == '\n'
        free(rd->file);
    }
    return (error);
}

// int			rd_loop(t_struct_rd *rd, t_shell *shell)
// {
//     char    *cache;
//     int     error;
//     t_struct_m	*echo;
    
//     echo = ft_calloc(1, sizeof(t_struct_m));
//     rd->i = 0;
//     rd->file = ft_strdup("");
//     while ((rd->str[rd->i] || rd->str[rd->i] != '\n') && error == 0)
//     {
//         set_value_rd(rd);
//         error = rd_check_error_rd(rd);//get the rd
//         if (error == 0)
//             error = error_sytax(rd);//get if rd is too much
//         if (error != 0)
//             return (error);
//         printf("---start---\n");  
//         cache = cut_string_shell(rd->str, rd, shell);
//         free(rd->file);
//         rd->file = ft_strdup(echo_main(cache, echo, shell));
//         free(cache);
//         while (rd->str[rd->i] == ' ')
//             rd->i++;
//         if (rd->str[rd->i] == '>')
//         {
//             ft_printf("[%s], ", rd->file);
//             // error = make_file(rd);
//         }
//         else
//         {
//             cache = rd_save_echo(rd);
//             rd->cache = ft_strdup(echo_main(cache, echo, shell));
//             free(cache);
//             cache = ft_strjoin(rd->string, rd->cache);
//             free(rd->string);
//             free(rd->cache);
//             rd->string = ft_strdup(cache);
//             if (rd->str[rd->i] == '\n' || rd->str[rd->i])
//             {
//                 // error = rd_input_file(rd);
//                 ft_printf("[%s], ", rd->file);
//                 ft_printf("[%s]\n", rd->txt);
//                 return (error);
//             }
//             else
//             {
                
//                 ft_printf("[%s], ", rd->file);
//                 // error = make_file(rd);
//             }
//         }
//     }
//     return (error);
// }
