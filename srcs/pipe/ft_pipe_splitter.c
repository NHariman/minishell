/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pipe_splitter.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 22:09:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/12/06 21:41:13 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		ft_count_pipes(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
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

void			ft_pipe_splitter(char *str, t_shell *shell)
{
	char	**pipes;
	int		len;

	len = ft_count_pipes(str) + 1;
	pipes = (char **)malloc(sizeof(char *) * (len + 1));
	if (!pipes)
		ft_malloc_fail();
	pipes[len] = (char *)0;
	pipes = ft_fill_prompts(pipes, str, len, '|');
	int k = 0;
	while (pipes[k] != (char *)0)
	{
		ft_printf("pipes[%i]: {%s}\n", k, pipes[k]);
		k++;
	}
	ft_printf("lol pipes, what's in shell?\n");
	ft_printf("shell->env[0]: %s\n", shell->env[0]);
	// int k = 0;
	// while (shell->env[k] != (char *)0)
	// {
	// 	ft_printf("shell->env[%i]: {%s}\n", k, shell->env[k]);
	// 	k++;
	// }
	ft_printf("and now the string:\n{%s}\n", str);
}
