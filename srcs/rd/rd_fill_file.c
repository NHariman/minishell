/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_fill_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:48 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/12 22:57:32 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

// static void	rd_one(t_struct_rd *rd)
// {
// 	pid_t	child_pid;
// 	pid_t	tpid;
// 	int		child_status;

// 	tpid = 0;
// 	child_pid = fork();
// 	if (child_pid == 0)
// 	{
// 		dup2(rd->fd, 1);
// 		ft_wordparser();
// 		close(1);
// 		close(rd->fd);
// 		exit(0);
// 	}
// 	else
// 	{
// 		while (tpid != child_pid)
// 		{
// 			tpid = wait(&child_status);
// 		}
// 	}
// }

// static void	rd_two(t_struct_rd *rd)
// {
// 	pid_t	child_pid;
// 	pid_t	tpid;
// 	int		child_status;

// 	tpid = 0;
// 	child_pid = fork();
// 	if (child_pid == 0)
// 	{
// 		dup2(rd->fd_rd, 0);
// 		ft_wordparser();
// 		close(0);
// 		close(rd->fd_rd);
// 		exit(0);
// 	}
// 	else
// 	{
// 		while (tpid != child_pid)
// 		{
// 			tpid = wait(&child_status);
// 		}
// 	}
// }

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

static void	do_rd(t_struct_rd *rd)
{

	if (rd->fd != -1)
	{
		g_shell.tmp_std[OUT] = rd->fd;
		dup2(rd->fd, 1);
		close(rd->fd);
	}
	if (rd->fd_rd != -1)
	{
		g_shell.tmp_std[IN] = rd->fd_rd;
		dup2(rd->fd_rd, 0);
		close(rd->fd_rd);
	}
}

void	rd_open_file_fill(t_struct_rd *rd)
{
	if (rd->fd != -1 || rd->fd_rd != -1)
	{
		do_rd(rd);
		if (rd->fd != -1)
			close(rd->fd);
		if (rd->fd_rd != -1)
			close(rd->fd_rd);
	}
	// if (rd->fd != -1)
	// {
	// 	rd_one(rd);
	// 	close(rd->fd);
	// }
	// else if (rd->fd_rd != -1)
	// {
	// 	rd_two(rd);
	// 	close(rd->fd_rd);
	// }
}
