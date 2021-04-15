/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_fill_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:48 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/15 11:04:45 by ybakker       ########   odam.nl         */
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
	int saved_stdout;
	
	saved_stdout = dup(1);

	g_shell.tmp_std[OUT] = rd->fd;
	dup2(rd->fd, 1);
	// ft_wordparser();
	close(rd->fd);

	dup2(saved_stdout, 1);
	close(saved_stdout);
}

static void	rd_in(t_struct_rd *rd)
{
	// int saved_stdin;
	
	// saved_stdin = dup(0);
	
	g_shell.tmp_std[IN] = rd->fd_rd;
	dup2(rd->fd_rd, 0);
	// ft_wordparser();
	close(rd->fd_rd);

	// dup2(saved_stdin, 0);
	// close(saved_stdin);
}

void	rd_open_file_fill(t_struct_rd *rd)
{
	ft_printf("[%i][%i]\n", rd->fd, rd->fd_rd);
	if (rd->store == 1 || rd->store == 2)
	{
		rd_out(rd);
		if (rd->fd_rd != -1)
			rd_in(rd);
	}
	else if (rd->store == 3)
	{
		rd_in(rd);
			rd_out(rd);
	}
	if (rd->fd != -1)
		close(rd->fd);
	if (rd->fd_rd != -1)
		close(rd->fd_rd);
	ft_printf("---DONE---\n");
}
