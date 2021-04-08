/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_error_check.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 14:41:40 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/08 16:54:01 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	syntax_left_double(char *line, int i)
{
	int	len;

	len = 0;
	if (line[i] == '<')
	{
		while (line[i] == '<')
		{
			len++;
			i++;
		}
	}
	else
		return (0);
	if (len == 1)
		ft_printf_err("minishell: syntax error near unexpected token `<'\n");
	if (len == 2)
		ft_printf_err("minishell: syntax error near unexpected token `<<'\n");
	if (len >= 3)
		ft_printf_err("minishell: syntax error near unexpected token `<<<'\n");
	return (-1);
}

static int	syntax_right_double(char *line, int i)
{
	int	len;

	len = 0;
	if (line[i] == '>')
	{
		while (line[i] == '>')
		{
			len++;
			i++;
		}
	}
	else
		return (0);
	if (len >= 1 && len <= 2)
		ft_printf_err("minishell: syntax error near unexpected token `>'\n");
	else
		ft_printf_err("minishell: syntax error near unexpected token `>>'\n");
	return (-1);
}

int	check_rd_left(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i] == '<')
	{
		i++;
		len++;
	}
	if (check_red_two_error(len) == -1)
		return (-1);
	while (line[i] == ' ')
		i++;
	if (line[i] == '<' || (line[i] == '>'))
	{
		if (syntax_left_double(line, i) || syntax_right_double(line, i))
			return (-1);
	}
	return (0);
}

int	check_rd_right(char *line, int i)
{
	int	len;

	len = 0;
	while (line[i] == '>')
	{
		i++;
		len++;
	}
	if (check_red_one_error(len) == -1)
		return (-1);
	while (line[i] == ' ')
		i++;
	if (line[i] == '<' || (line[i] == '>'))
	{
		if (syntax_left_double(line, i) || syntax_right_double(line, i))
			return (-1);
	}
	return (0);
}
