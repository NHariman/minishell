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

void	rd_open_file(t_struct_rd *rd)
{
	errno = 0;
	if (rd->fd != -1)
		close(rd->fd);
	else if (rd->fd_rd != -1 && rd->nb == 3)
		close(rd->fd_rd);
	if (ft_strcmp(rd->file, "") == 0)
	{
		ft_printf("bash: syntax error near unexpected token `newline'\n");
		g_shell.exit_code = 258;
	}
	else
	{
		if (rd->nb == 1)
			rd->fd = open(rd->file, O_RDWR | O_TRUNC | O_CREAT, 0666);
		else if (rd->nb == 2)
			rd->fd = open(rd->file, O_RDWR | O_APPEND | O_CREAT, 0666);
		else if (rd->nb == 3)
			rd->fd_rd = open(rd->file, O_RDWR);
		if (rd->fd < 0 && rd->fd_rd < 0)
		{
			ft_printf_err("bash: %s: %s\n", rd->file, strerror(errno));
			g_shell.exit_code = 1;
		}
	}
}
