/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_newline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 14:32:54 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/08 15:55:13 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	syntax_newline(char *line, int i)
{
	int y;

	y = i;
	if (line[i] == '\0')
	{
		ft_printf_err("minishell: syntax error ");
		ft_printf_err("near unexpected token `newline'\n");
		g_shell.exit_code = 258;
		return (-1);
	}
	return (0);
}
