/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_open_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:14 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 14:42:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void	rd_file_error(t_struct_rd *rd)
{
	if (rd->fd < 0 && rd->fd_rd < 0)
	{
		ft_printf_err("minishell: %s: %s\n", rd->file, strerror(errno));
		g_shell.exit_code = 1;
		rd->error = 1;
	}
	else if (rd->str[rd->i] && rd->str[rd->i] != '\n' && rd->error == 0)
	{
		if (rd->nb == 1 && rd->nb == 2)
			close(rd->fd);
		else if (rd->nb == 3)
			close(rd->fd_rd);
	}
}

void	rd_open_file(t_struct_rd *rd)
{
	errno = 0;
	if (rd->fd != -1)
		close(rd->fd);
	else if (rd->fd_rd != -1 && rd->nb == 3)
		close(rd->fd_rd);
	if (ft_strcmp(rd->file, "") == 0)
	{
		ft_printf_err("minishell: syntax error near unexpected token `newline'\n");
		g_shell.exit_code = 258;
		rd->error = 1;
	}
	else
	{
		if (rd->nb == 1)
			rd->fd = open(rd->file, O_RDWR | O_TRUNC | O_CREAT, 0666);
		else if (rd->nb == 2)
			rd->fd = open(rd->file, O_RDWR | O_APPEND | O_CREAT, 0666);
		else if (rd->nb == 3)
			rd->fd_rd = open(rd->file, O_RDWR);
	}
	rd_file_error(rd);
}
