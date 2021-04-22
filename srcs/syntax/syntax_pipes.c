/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_pipes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 19:28:56 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/22 07:21:33 by ybakker       ########   odam.nl         */
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
	if (check_front_token(line, i))
		return (syntax_pipe_error());
	i = i + ft_iswhitespaces(line + i + 1) + 1;
	if (is_token(line[i]) || line[i] == '\0')
	{
        if (line[i] == '\0')
            ft_putstr_fd(
                "minishell: error: multiline pipes not supported\n", 2);
        return (syntax_pipe_error());
    }
    return (0);
}

int syntax_pipes_y(char *line, int i)
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