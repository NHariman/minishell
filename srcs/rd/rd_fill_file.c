/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_fill_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:48 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/15 14:17:03 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	wait_for_process(void)
{
	while (g_shell.tpid != g_shell.child_pid)
		g_shell.tpid = wait(&g_shell.child_status);
	g_shell.exit_code = get_exit_code(g_shell.child_status);
	g_shell.child_pid = -2;
	g_shell.tpid = -2;
}

void	restore_fds(int *new_fds)
{
	if (new_fds[IN] != STDIN_FILENO)
		dup2(g_shell.tmp_std[IN], STDIN_FILENO);
	if (new_fds[OUT] != STDOUT_FILENO)
		dup2(g_shell.tmp_std[OUT], STDOUT_FILENO);
	if (new_fds[IN] != -1)
		close(new_fds[IN]);
	if (new_fds[OUT] != -1)
		close(new_fds[OUT]);
}

static void	rd_in(int signal, int fd, int *new_fds)
{
	g_shell.tmp_std[signal] = dup(signal);
	new_fds[signal] = fd;
	dup2(fd, 0);
}

void	rd_open_file_fill(t_struct_rd *rd, int *new_fds)
{
	if (rd->out != -1)
		rd_out(OUT, rd->out, new_fds);
	if (rd->in != -1)
		rd_in(IN, rd->in, new_fds);
}
