/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_and_child.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 11:31:27 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/06 23:08:14 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pipe_child(int **p, char **pipes, int i, int fd_in)
{
	dup2(fd_in, 0);
	if (pipes[i + 1] != (char *) 0)
		dup2(p[i][1], 1);
	close(p[i][0]);
	function_dispatcher(pipes[i]);
	ft_clear_shell();
	exit(0);
}

int	get_exit_code(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (0);
}

void	free_p(int **p, int len)
{
	int	i;

	i = 0;
	if (!p)
		return ;
	while (i < len)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

void	pipe_parent(int *fd_in, int *i, int **p, char **pipes)
{
	int	status;

	wait(&status);
	close(p[*i][1]);
	*fd_in = p[*i][0];
	if (pipes[*i + 1] == (char *) 0)
	{
		close(p[*i][0]);
		g_shell.exit_code = get_exit_code(status);
	}
	if (*i != 0)
		close(p[*i - 1][0]);
	free(pipes[*i]);
	*i = *i + 1;
}
