/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_full_check.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 14:57:02 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/28 19:45:08 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	syntax_backslash(void)
{
	ft_printf_err("minishell: syntax error near unexpected token '\\\'\n");
	g_shell.exit_code = 258;
	return (-1);
}

int	ft_semicol_error(void)
{
	ft_printf_err("minishell: syntax error near unexpected token `;'\n");
	g_shell.exit_code = 258;
	return (-1);
}

int	semicolin_check(char *line, int i)
{
	int	start;

	start = i;
	start++;
	if (line[start] == ';')
		return (ft_semicol_error());
	while (line[start] == ' ' || line[start] == '<' || line[start] == '>')
		start++;
	if (line[start] == ';')
		return (ft_semicol_error());
	return (0);
}

static int	is_token_check(char c, char *line, int i)
{
	if (c == '|')
	{
		if (syntax_pipes(line, i) == -1)
			return (-1);
	}
	else if (c == ';')
	{
		if (semicolin_check(line, i) == -1)
			return (-1);
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
	int	y;

	i = 0;
	y = i + ft_iswhitespaces(line + i + 1) + 1;
	if (line[0] == ';')
		return (ft_semicol_err());
	else if (line[y] == '|')
	{
		if (syntax_pipes(line, i - 1) == -1)
			return (-1);
	}
	while (line[i])
	{
		if (ft_strchr("\'\"", line[i]) && ft_backslash_check(line, i) % 2 == 0)
			ft_skip_quotes(line, &i, line[i]);
		else if (is_token_check(line[i], line, i))
			return (-1);
		else
			i++;
	}
	return (0);
}
