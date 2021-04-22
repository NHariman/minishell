/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_pipes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 19:28:56 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/22 11:19:51 by ybakker       ########   odam.nl         */
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
    // ft_printf("i == [%i] c == [%c]\n", start, line[start]);
    while (line[start] == ' ' || line[start] == '<' || line[start] == '>')
    {
        start++;
    }
    // ft_printf("i == [%i] c == [%c]\n", start, line[start]);
    if (line[start] == '|')
        return (syntax_pipe_error());
    return (0);
}
