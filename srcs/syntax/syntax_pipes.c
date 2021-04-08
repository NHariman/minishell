/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SYNTAX_PIPES.C                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 19:28:56 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/08 19:46:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
static int syntax_pipe_error(void)
{
    ft_printf_err("minishell: syntax error near unexpected token `|'\n");
    g_shell.exit_code = 258;
    return (-1);
}

int syntax_pipes(char *line, int i)
{
    int start;

    start = i;
    start++;
    while (line[start] != '|' && line[start])
        start++;
    if (line[start] == '|')
	    return (syntax_pipe_error());
    start = i;
    start++;
    while (line[i] == ' ')
        start++;
    if (line[i] == ';')
        return(ft_semicol_err());
    else if (line[i] == '\0')
        return (syntax_pipe_error());
    return (0);
}