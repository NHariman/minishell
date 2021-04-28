/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_and_child.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 11:31:27 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/28 22:33:58 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_for_pids(pid_t *pids, int i)
{
	int	nb;

	nb = 0;
	while(nb < i + 1)
	{
		wait(&pids[nb]);
		nb++;
	}
}

void	pipe_child(int **p, char **pipes, int i)
{

	if (pipes[i + 1] != (char *) 0)
	{
		dup2(p[i][1], STDOUT_FILENO);
		close(p[i][1]);
	}
	ft_putstr_fd("there\n", 2);
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

void	pipe_parent(int *i, int **p, char **pipes, pid_t *pids)
{
	int	status;

	close(p[*i][1]);
	if (*i != 0)
		close(p[*i - 1][0]);
	if (pipes[*i + 1] == (char *) 0)
	{
		wait_for_pids(pids, *i - 1);
		waitpid(pids[*i], &status, 0);
		close(p[*i][0]);
		g_shell.exit_code = get_exit_code(status);
	}
	*i = *i + 1;
}
