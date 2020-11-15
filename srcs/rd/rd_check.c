/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/15 16:59:25 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void        ft_check_rd_echo(t_struct_rd *rd, t_shell *shell)
{
    free(rd->string);
    rd->string = ft_strdup(shell->echo);
    rd->txt = 0;
}

int			ft_check_rd(t_struct_rd *rd, t_shell *shell)
{
    if (shell->check->echo == 1)
        ft_check_rd_echo(t_struct_rd *rd, t_shell *shell);
    else
        return (1);
    return (0);
}