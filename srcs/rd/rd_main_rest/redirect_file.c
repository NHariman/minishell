/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 15:19:40 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/28 17:25:59 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../get_next_line_yusha/get_next_line_yusha.h"
#include <stdio.h>

void        redirect_file(int fd, t_shell *shell)
{
    char    *str;
    int     count;
    char    *cache;
    char    *tmp;
    // char    **split;
    // int     i;

    cache = ft_strdup("");
    count = shell->exit_code;
    count = 1;
    while (count > 0)
    {
        count = get_next_line_yusha(fd, &str);
        tmp = ft_strjoin(cache, str);
        free(cache);
        free(str);
        cache = ft_strjoin(tmp, "\n");
    }
    // split = ft_split(cache, '\n');
    // i = 0;
    // while (split[i])
    //     i++;
    // split[i] = (char*)0;
    // i = 0;
    // while (split[i])
    // {
    //     ft_printf("[%s]\n", split[i]);
    //     i++;
    // }
    shell->nb_file_input = ft_strdup(cache);
    free(cache);
}
