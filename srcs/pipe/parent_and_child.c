/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_and_child.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 11:31:27 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 19:37:52 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_child(int *p, char **pipes, int i, int fd_in)
{
	dup2(fd_in, 0);
	if (pipes[i + 1] != (char *) 0)
		dup2(p[1], 1);
	close(p[0]);
	function_dispatcher(pipes[i]);
	exit(0);
}

static int	get_exit_code(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (0);
}

void	pipe_parent(int *fd_in, int *i, int *p, char **pipes)
{
	int	status;

	wait(&status);
	close(p[1]);
	*fd_in = p[0];
	*i = *i + 1;
	if (pipes[*i + 1] == (char *) 0)
		shell.exit_code = get_exit_code(status);
}
