/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_fill_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:48 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/15 13:27:30 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	wait_for_process(void)
{
	while (g_shell.tpid != g_shell.child_pid)
		g_shell.tpid = wait(&g_shell.child_status);
	g_shell.exit_code = get_exit_code(g_shell.child_status);
}

void	save_std(int *og_std)
{
	og_std[IN] = dup(STDIN_FILENO);
	og_std[OUT] = dup(STDOUT_FILENO);
	if (og_std[IN] == - 1|| og_std[OUT] == -1)
		error_exit("Error: Unable to reset stds\n", -1);
}

void	restore_std(int *og_std)
{
	if (dup2(og_std[IN], STDIN_FILENO) == -1
		|| dup2(og_std[OUT], STDOUT_FILENO) == -1)
		error_exit("Error: Unable to reset stds\n", -1);
	if (close(og_std[IN]) == - 1 || close(og_std[OUT]) == -1)
		error_exit("Error: Unable to close std\n", -1);
}

static void	rd_out(t_struct_rd *rd)
{
	g_shell.tmp_std[OUT] = rd->out;
	ft_printf("---2---\n");
	dup2(rd->out, 1);
	ft_printf("---3---\n");
	close(rd->out);
	ft_printf("---4---\n");
}

static void	rd_in(t_struct_rd *rd)
{
	g_shell.tmp_std[IN] = rd->in;
	dup2(rd->in, 0);
	close(rd->in);
}

void	rd_open_file_fill(t_struct_rd *rd)
{
	if (rd->store == 1 || rd->store == 2)
	{
		ft_printf("---1---\n");
		rd_out(rd);
		ft_printf("---5---\n");
		if (rd->in != -1)
			rd_in(rd);
		ft_printf("---6---\n");
	}
	else if (rd->store == 3)
	{
		rd_in(rd);
		if (rd->out != -1)
			rd_out(rd);
	}
	if (rd->out != -1)
		close(rd->out);
	if (rd->in != -1)
		close(rd->in);
	ft_printf("---DONE---\n");
}
