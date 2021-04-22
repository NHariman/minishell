/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_open_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:14 by ybakker       #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/04/15 20:14:03 by nhariman      ########   odam.nl         */
=======
/*   Updated: 2021/04/16 13:41:16 by ybakker       ########   odam.nl         */
>>>>>>> 06b726ef015b187d248b356a0e1ec19d99f6b74d
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
<<<<<<< HEAD
	{
		ft_printf("filename out = [%s]\n", rd->file);
		rd->out = open(rd->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		ft_printf("fd = [%i]\n", rd->out);
	}
	else if (rd->nb == 2)
	{
		ft_printf("filename out = [%s]\n", rd->file);
		rd->out = open(rd->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
		ft_printf("fd = [%i]\n", rd->out);
	}
	else if (rd->nb == 3)
	{
		ft_printf("filename in = [%s]\n", rd->file);
		rd->in = open(rd->file, O_RDONLY);
		ft_printf("fd_rd = [%i]\n", rd->in);
	}
	if (rd->error != 1)
		rd_file_error(rd);
=======
		rd_open_out(rd, O_TRUNC);
	else if (rd->nb == 2)
		rd_open_out(rd, O_APPEND);
	else if (rd->nb == 3)
		rd_open_in(rd);
	ft_printf("open IN = [%i] OUT = [%i]\n", rd->in, rd->out);
	ft_printf("open IN = [%i] OUT = [%i]\n", read(rd->in, NULL, 0), read(rd->out, NULL, 0));
	ft_printf("---DONE2---\n");
>>>>>>> 06b726ef015b187d248b356a0e1ec19d99f6b74d
}
