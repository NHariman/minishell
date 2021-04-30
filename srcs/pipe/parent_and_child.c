/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_and_child.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 11:31:27 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/30 19:48:50 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	wait_for_children(int **p, char **pipes)
{
	int	i;
	int	len;
	int	status;

	len = ft_arrlen(pipes);
	i = 0;
	while (i < len - 1)
	{
		waitpid(p[i][3], &status, 0);
		i++;
	}
}

void	pipe_child(int **p, char **pipes, int i)
{
	if (pipes[i + 1] != (char *) 0)
	{
		dup2(p[i][1], STDOUT_FILENO);
		close(p[i][1]);
	}
	if (i != 0)
	{
		dup2(p[i - 1][0], STDIN_FILENO);
		close(p[i - 1][0]);
	}
	function_dispatcher(pipes[i]);
	ft_clear_shell();
	exit(g_shell.exit_code);
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

void	pipe_parent(int *i, int **p, char **pipes, pid_t pid)
{
	int	status;

	close(p[*i][1]);
	if (*i != 0)
		close(p[*i - 1][0]);
	if (pipes[*i + 1] == (char *) 0)
	{
		close(p[*i][0]);
		waitpid(pid, &status, 0);
		wait_for_children(p, pipes);
		g_shell.exit_code = get_exit_code(status);
	}
	*i = *i + 1;
}
