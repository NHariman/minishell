/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_pipes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 19:28:56 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/22 11:01:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int syntax_pipe_error(void)
{
    ft_printf_err("minishell: syntax error near unexpected token `|'\n");
    g_shell.exit_code = 258;
    return (-1);
}

static int syntax_multiline_error(void)
{
    ft_putstr_fd(
                "minishell: error: multiline pipes not supported\n", 2);
    g_shell.exit_code = 258;
    return (-1);
}

int syntax_pipes(char *line, int i)
{
    int start;

    start = i;
    start++;
    if (line[start] == '|' || line[start] == '\0')
        return (syntax_multiline_error());
    while (line[start] == ' '  || line[start] == '<' || line[start] == '>')
    {
        if (line[start] == '\'' || line[start] == '\"')
            ft_skip_quotes(line, &start, line[start]);
        else
            start++;
    }
    if (line[start] == '|')
        return (syntax_pipe_error());
    else if (line[start] == ';')
        return(ft_semicol_err());
    return (0);
}
