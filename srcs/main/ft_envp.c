/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_envp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 15:32:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/25 21:05:46 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_envlen(t_shell *shell)
{
	int i;

	i = 0;
	while (shell->env[i] != (char *)0)
		i++;
	return (i);
}

void	ft_add_env_back(t_shell *shell, char *input)
{
	char	**new_envp;
	int		len;
	int		i;

	len = ft_envlen(shell);
	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new_envp)
	{
		ft_printf_err("Error\nMalloc failed.\n");
		exit(1);
	}
	new_envp[len + 1] = (char *)0;
	while (shell->env[i])
	{
		new_envp[i] = ft_strdup(shell->env[i]);
		i++;
	}
	new_envp[i] = ft_strdup(input);
	free(input);
	ft_free_array(shell->env, len);
	shell->env = new_envp;
}
