/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_open_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:14 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/16 13:20:39 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void	rd_file_error(t_struct_rd *rd)
{
	if (rd->out < 0 && rd->in < 0)
	{
		ft_printf_err("minishell: %s: %s\n", rd->file, strerror(errno));
		g_shell.exit_code = 1;
		rd->error = 1;
	}
	else if (rd->str[rd->i] && rd->str[rd->i] != '\n' && rd->error == 0)
	{
		if (rd->nb == 1 || rd->nb == 2)
			close(rd->out);
		else if (rd->nb == 3)
			close(rd->in);
	}
}

void	rd_open_file(t_struct_rd *rd)
{
	errno = 0;
	open_check();
	if (rd->out != -1 && (rd->nb == 1 || rd->nb == 2))
	{
		ft_printf("close fd\n");
		close(rd->out);
	}
	else if (rd->in != -1 && rd->nb == 3)
	{
		ft_printf("close fd_rd\n");
		close(rd->in);
	}
	if (rd->nb == 1)
		rd->out = open(rd->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (rd->nb == 2)
		rd->out = open(rd->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else if (rd->nb == 3)
		rd->in = open(rd->file, O_RDWR, 0644);
	if (rd->error != 1)
		rd_file_error(rd);
	ft_printf("IN = [%i] OUT = [%i]\n", rd->in, rd->out);
	ft_printf("IN = [%i] OUT = [%i]\n", read(rd->in, NULL, 0), read(rd->out, NULL, 0));
	ft_printf("---DONE2---\n");
}
