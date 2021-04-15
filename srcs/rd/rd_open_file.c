/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_open_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:14 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/15 12:01:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void	rd_file_error(t_struct_rd *rd)
{
	if (rd->stdout < 0 && rd->stdin < 0)
	{
		ft_printf_err("minishell: %s: %s\n", rd->file, strerror(errno));
		g_shell.exit_code = 1;
		rd->error = 1;
	}
	else if (rd->str[rd->i] && rd->str[rd->i] != '\n' && rd->error == 0)
	{
		if (rd->nb == 1 || rd->nb == 2)
			close(rd->stdout);
		else if (rd->nb == 3)
			close(rd->stdin);
	}
}

void	rd_open_file(t_struct_rd *rd)
{
	errno = 0;
	int		fd;
	
	fd = -1;
	if (rd->stdout != -1 && (rd->nb == 1 || rd->nb == 2))
	{
		ft_printf("close fd");
		close(rd->stdout);
	}
	else if (rd->stdin != -1 && rd->nb == 3)
	{
		ft_printf("close fd_rd");
		close(rd->stdin);
	}
	if (rd->nb == 1)
	{
		rd->stdout = open(rd->file, O_RDWR | O_TRUNC | O_CREAT, 0666);
		ft_printf("fd = [%i]\n", rd->stdout);
	}
	else if (rd->nb == 2)
	{
		rd->stdout = open(rd->file, O_RDWR | O_APPEND | O_CREAT, 0666);
		ft_printf("fd = [%i]\n", rd->stdout);
	}
	else if (rd->nb == 3)
	{
		rd->stdin = open(rd->file, O_RDWR);
		ft_printf("fd_rd = [%i]\n", rd->stdin);
	}
	if (rd->error != 1)
		rd_file_error(rd);
}
