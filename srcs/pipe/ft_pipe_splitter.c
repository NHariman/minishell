/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pipe_splitter.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 22:09:14 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/12 17:22:21 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		ft_count_pipes(char *str)
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

void			loop_pipe(char **pipes, t_shell *shell)
{
	int		p[2];
	pid_t	pid;
	int		fd_in;
	int		i;

	i = 0;
	while (pipes[i] != (char *)0)
	{
		pipe(p);
		if ((pid = fork()) == -1)
			exit(1);
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (pipes[i + 1] != (char *)0)
				dup2(p[1], 1);
			close(p[0]);
			function_dispatcher(pipes[i], shell);
			exit(0);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			i++;
		}
	}
}

void			ft_pipe_splitter(char *str, t_shell *shell)
{
	char	**pipes;
	int		len;

	len = ft_count_pipes(str);
	pipes = (char **)malloc(sizeof(char *) * (len + 1));
	if (!pipes)
		ft_malloc_fail();
	pipes = ft_fill_prompts(pipes, str, len, '|');
	pipes[len] = (char *)0;
	int k = 0;
	while (pipes[k] != (char *)0)
	{
		ft_printf("pipes[%i]: {%s}\n", k, pipes[k]);
		k++;
	}
	loop_pipe(pipes, shell);
}
