/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_open_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:14 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/16 13:41:16 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void	rd_open_out(t_struct_rd *rd, int flag)
{
	if (rd->out != -1)
		close(rd->out);
	rd->out = open(rd->file, O_CREAT | flag | O_WRONLY, 0644);
	if (rd->out == -1)
	{
		ft_printf_err("minishell: %s: %s\n", rd->file, strerror(errno));
		g_shell.exit_code = 1;
		rd->error = 1;
	}
}

static void	rd_open_in(t_struct_rd *rd)
{
	if (rd->in != -1)
		close(rd->in);
	rd->in = open(rd->file, O_RDWR, 0644);
	if (rd->in == -1)
	{
		ft_printf_err("minishell: %s: %s\n", rd->file, strerror(errno));
		g_shell.exit_code = 1;
		rd->error = 1;
	}
}

void	rd_open_file(t_struct_rd *rd)
{
	errno = 0;
	if (rd->nb == 1)
		rd_open_out(rd, O_TRUNC);
	else if (rd->nb == 2)
		rd_open_out(rd, O_APPEND);
	else if (rd->nb == 3)
		rd_open_in(rd);
}
