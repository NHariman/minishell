/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:15:13 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/23 22:38:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_array(char **arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_clear_shell(t_shell *shell)
{
	shell->check.echo = 0;
	shell->check.env = 0;
	shell->check.exp = 0;
	shell->check.err = 0;
	shell->check.pwd = 0;
	if (shell->echo)
	{
		shell->echo = NULL;
		free(shell->echo);
	}
	if (shell->echo)
	{
		shell->echo = NULL;
		free(shell->echo);
	}
	if (shell->pwd)
	{
		shell->pwd = NULL;
		free(shell->pwd);
	}
	if (shell->env_s)
	{
		shell->env_s = NULL;
		free(shell->env_s);
	}
	if (shell->err)
	{
		shell->err = NULL;
		free(shell->err);
	}
}
