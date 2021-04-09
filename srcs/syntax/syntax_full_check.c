/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_full_check.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 14:57:02 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/08 19:42:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	syntax_backslash(void)
{
	ft_printf_err("minishell: syntax error near unexpected token '\\\'\n");
	g_shell.exit_code = 258;
	return (-1);
}

static int	is_token_check(char c, char *line, int i)
{
	if (c == '|')
	{
		if (syntax_pipes(line, i))
			return (-1);
	}
	else if (c == ';')
	{
		if (check_front_token(line, i))
			return (ft_semicol_err());
		i = i + ft_iswhitespaces(line + i + 1) + 1;
		if (is_token(line[i]))
			return (ft_semicol_err());
	}
	else if (c == '>')
	{
		if (check_rd_right(line, i) || check_rd_newline(line, i, '>'))
			return (-1);
	}
	else if (c == '<')
	{
		if (check_rd_left(line, i) || check_rd_newline(line, i, '<'))
			return (-1);
	}
	else if (line[i] == '\\')
		return (syntax_backslash());
	return (0);
}

int	syntax_full_check(char *line)
{
	int	i;

	i = 0;
	if (line[0] == ';')
		return (ft_semicol_err());
	while (line[i])
	{
		if (ft_strchr("\'\"", line[i]) && ft_backslash_check(line, i) % 2 == 0)
			ft_skip_quotes(line, &i, line[i]);
		else if (is_token_check(line[i], line, i))
			return (-1);
		i++;
	}
	return (0);
}
