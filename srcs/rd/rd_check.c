/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/12/01 14:52:17 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
check > > >
if no file inbetween, then fail
check >>>>
check <<<<
*/

int				rd_check_error_rd(t_struct_rd *rd, t_shell *shell)
{
    int     len;
    int     i;

    len = 0;
    i = rd->i;
	if (rd->str[i] == '<')
	{
        while (rd->str[i] == '<')
        {
            i++;
            len++;   
        }
        if (len == 1)
            return (0);
        else if (len >= 2 && len < 4)
            ft_printf("bash: syntax error near unexpected token `<'\n");
        else if (len == 5)
            ft_printf("bash: syntax error near unexpected token `<<'\n");
        else if (len >= 6)
            ft_printf("bash: syntax error near unexpected token `<<<'\n");
	}
	else if (rd->str[i] == '>')
	{
		while (rd->str[i] == '>')
        {
            i++;
            len++;
        }
        if (len == 1)
            return (0);
        else if (len == 2)
            ft_printf("bash: syntax error near unexpected token `>'\n");
        else if (len > 2)
            ft_printf("bash: syntax error near unexpected token `>>'\n");
	}
    else
    {
        printf("there is no redirect?\n");
    }
    shell->exit_code = 1;
	return (shell->exit_code = 1);
}
