/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_open_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:14 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/15 18:00:15 by ybakker       ########   odam.nl         */
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
	int errno;

	errno = 0;
	if (rd->out != -1 && (rd->nb == 1 || rd->nb == 2))
	{
		ft_printf("close OUT\n");
		close(rd->out);
		rd->out = -1;
		ft_printf("error OUT [%i] read\n", read(rd->out, NULL, 0));
		ft_printf("error OUT [%i] fd\n", rd->out);
	}
	else if (rd->in != -1 && rd->nb == 3)
	{
		ft_printf("close IN\n");
		close(rd->in);
		rd->in = -1;
		ft_printf("error IN [%i] read\n", read(rd->in, NULL, 0));
		ft_printf("error IN [%i] fd\n",  rd->in);
	}
	if (rd->nb == 1)
	{
		rd->out = open(rd->file, O_RDWR | O_TRUNC | O_CREAT, 0666);
		ft_printf("OUT [%i]\n",  rd->out);
		ft_printf_err("out: %s: %s\n", rd->file, strerror(errno));
	}
	else if (rd->nb == 2)
	{
		rd->out = open(rd->file, O_RDWR | O_APPEND | O_CREAT, 0666);
		ft_printf("OUT [%i]\n",  rd->out);
		ft_printf_err("out: %s: %s\n", rd->file, strerror(errno));	
	}
	else if (rd->nb == 3)
	{
		rd->in = open(rd->file, O_RDWR);
		ft_printf("IN = [%i]\n",  rd->in);
		ft_printf_err("in: %s: %s\n", rd->file, strerror(errno));
	}
	if (rd->error != 1)
		rd_file_error(rd);
	ft_printf("IN = [%i]\n",  rd->in);
	ft_printf("IN = [%i]\n", read(rd->in, NULL, 0));
	ft_printf_err("%s\n", strerror(errno));
	errno = 0;
	ft_printf("OUT [%i]\n", read(rd->out, NULL, 0));
	ft_printf("OUT [%i]\n",  rd->out);
	ft_printf_err("%s\n", strerror(errno)); 
	ft_printf("---DONE2---\n");
}
