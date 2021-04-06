/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pipe_splitter.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 22:09:14 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/06 23:08:09 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_count_pipes(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (ft_strchr("\'\"", str[i]) && ft_backslash_check(str, i) % 2 == 0)
			ft_skip_quotes(str, &i, str[i]);
		else if (str[i] == '\\')
			i = i + 2;
		else if (str[i] == '|')
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static void	loop_pipe(char **pipes, int **p)
{
	pid_t	pid;
	int		fd_in;
	int		i;

	i = 0;
	fd_in = 0;
	while (pipes[i] != (char *) 0)
	{
		pipe(p[i]);
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
			pipe_child(p, pipes, i, fd_in);
		else
			pipe_parent(&fd_in, &i, p, pipes);
	}
}

static int	**make_p_array(int len)
{
	int	**p;
	int	i;

	p = (int **)malloc(sizeof(int *) * len);
	if (!p)
		ft_malloc_fail("make_p_array, p maker");
	i = 0;
	while (i < len)
	{
		p[i] = (int *)malloc(sizeof(int) * 2);
		if (!p[i])
			ft_malloc_fail("make_p_array, p[i] maker");
		i++;
	}
	return (p);
}

void	ft_pipe_splitter(char *str)
{
	char	**pipes;
	int		len;
	int		**p;

	len = ft_count_pipes(str);
	p = make_p_array(len);
	if (!p)
		ft_malloc_fail("ft_pipe_splitter, p maker");
	pipes = (char **)malloc(sizeof(char *) * (len + 1));
	if (!pipes)
		ft_malloc_fail("ft_pipe_splitter");
	pipes = ft_fill_prompts(pipes, str, len, '|');
	pipes[len] = (char *) 0;
	loop_pipe(pipes, p);
	free(pipes);
	free_p(p, len);
}
