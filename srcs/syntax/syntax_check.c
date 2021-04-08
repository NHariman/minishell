/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 08:12:33 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/08 15:59:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_qts(char *line)
{
	t_qts	qts;

	ft_set_qts(&qts);
	ft_qt_start(line, &qts);
	if (qts.dq % 2 != 0 || qts.sq % 2 != 0)
	{
		ft_printf_err("minishell: syntax error, hanging quotes\n");
		g_shell.exit_code = 258;
		return (1);
	}
	return (0);
}

int	syntax_check(char *line)
{
	if (check_qts(line))
		return (g_shell.exit_code);
	if (syntax_full_check(line))
		return (g_shell.exit_code);
	return (0);
}
