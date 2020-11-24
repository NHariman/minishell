/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   detail_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:50:43 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/23 21:18:02 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** for improvement: copy the cmd word, lowercase it, compare it
** to echo and pwd, if correct, return the lowercased word
** else return the original.
*/

char		*ft_find_case_cmd(char *cmd)
{
	char *tmp;

	tmp = NULL;
	if (!ft_strcasecmp(cmd, "echo") || !ft_strcasecmp(cmd, "env") ||
		!ft_strcasecmp(cmd, "pwd"))
		tmp = ft_strlower(cmd);
	else
		tmp = ft_strdup(cmd);
	free(cmd);
	return (tmp);
}

int		ft_envlen(t_shell *shell)
{
	int i;

	i = 0;
	while (shell->env[i])
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
	new_envp = (char **)malloc(sizeof(char *) * (len + 1));
	while (shell->env[i])
	{
		new_envp[i] = shell->env[i];
		i++;
	}
	new_envp[i] = input;
	shell->env = new_envp;
}

