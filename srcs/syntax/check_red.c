/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_red.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 12:26:27 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/28 19:26:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_red_one_error(int len)
{
	if (len == 3)
	{
		ft_printf_err("minishell: syntax error near unexpected token `>'\n");
		g_shell.exit_code = 258;
		return (-1);
	}
	else if (len > 3)
	{
		ft_printf_err("minishell: syntax error near unexpected token `>>'\n");
		g_shell.exit_code = 258;
		return (-1);
	}
	return (0);
}

int	check_red_one(char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '>')
		{
			while (line[i] == '>')
			{
				len++;
				i++;
			}
			if (check_red_one_error(len) == -1)
				return (-1);
			else if (rd_syntax_error(line, i, len) == -1)
				return (-1);
		}
		i++;
		len = 0;
	}
	if (i == -1)
		return (-1);
	return (0);
}

int	check_red_two_error(int len)
{
	if (len == 1 || len == 3)
		return (0);
	else if (len >= 2 && len <= 4)
		ft_printf_err("minishell: syntax error near unexpected token `<'\n");
	else if (len == 5)
		ft_printf_err("minishell: syntax error near unexpected token `<<'\n");
	else if (len >= 6)
		ft_printf_err("minishell: syntax error near unexpected token `<<<'\n");
	g_shell.exit_code = 258;
	return (-1);
}

int	check_red_two(char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '<')
		{
			while (line[i] == '<')
			{
				len++;
				i++;
			}
			if (check_red_two_error(len) == -1)
				return (-1);
			else if (rd_syntax_error(line, i, len) == -1)
				return (-1);
		}
		i++;
		len = 0;
	}
	return (0);
}
