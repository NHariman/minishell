/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_pipes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 19:28:56 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/15 15:28:06 by nhariman      ########   odam.nl         */
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
