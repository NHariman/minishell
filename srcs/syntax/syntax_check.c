/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 08:12:33 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 18:47:42 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_bs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\\')
		{
			ft_printf_err("minishell: syntax error near unexpected token '\\\'\n");
			g_shell.exit_code = 258;
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	check_qts(char *line)
{
	t_qts	qts;

	ft_set_qts(&qts);
	ft_qt_start(line, &qts);
	if (qts.dq % 2 != 0 || qts.sq % 2 != 0)
	{
		ft_printf_err("Error\nHanging quotes. Parsing failed.\n");
		g_shell.exit_code = 258;
		return (1);
	}
	return (0);
}

int	syntax_check(char *line)
{
	if (check_qts(line))
		return (g_shell.exit_code);
	if (check_end(line))
		return (g_shell.exit_code);
	else if (check_red_one(line) || check_red_two(line) || check_bs(line))
		return (g_shell.exit_code);
	return (0);
}
