/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_fill_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:48 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 14:43:32 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void	rd_one(t_struct_rd *rd)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;

	tpid = 0;
	child_pid = fork();
	if (child_pid == 0)
	{
		dup2(rd->fd, 1);
		ft_wordparser();
		close(1);
		close(rd->fd);
		exit(0);
	}
	else
	{
		while (tpid != child_pid)
		{
			tpid = wait(&child_status);
		}
	}
}

static void	rd_two(t_struct_rd *rd)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;

	tpid = 0;
	child_pid = fork();
	if (child_pid == 0)
	{
		dup2(rd->fd_rd, 0);
		ft_wordparser();
		close(0);
		close(rd->fd_rd);
		exit(0);
	}
	else
	{
		while (tpid != child_pid)
		{
			tpid = wait(&child_status);
		}
	}
}

void	rd_open_file_fill(t_struct_rd *rd)
{
	if (rd->fd != -1)
	{
		rd_one(rd);
		close(rd->fd);
	}
	else if (rd->fd_rd != -1)
	{
		rd_two(rd);
		close(rd->fd_rd);
	}
}
