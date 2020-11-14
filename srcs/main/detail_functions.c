/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   detail_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 18:50:43 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/14 21:50:02 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** for improvement: copy the cmd word, lowercase it, compare it
** to echo and pwd, if correct, return the lowercased word
** else return the original.
*/

void		ft_find_echo_pwd(char **cmd)
{
	int		check[5];
	int		i;

	check[4] = 3;
	check[0] = 0;
	i = 0;
	if (ft_strchr("eE", *cmd[0]))
	{
		check[1] = ft_strchr("cC", cmd[0][1]) ? 0 : 1;
		check[2] = ft_strchr("hH", cmd[0][2]) ? 0 : 1;
		check[3] = ft_strchr("oO", cmd[0][3]) ? 0 : 1;
	}
	else if (ft_strchr("pP", *cmd[0]))
	{
		check[1] = ft_strchr("wW", cmd[0][1]) ? 0 : 1;
		check[2] = ft_strchr("dD", cmd[0][2]) ? 0 : 1;
		check[3] = 0;
	}
	while (i != 4)
	{
		if (check[i] != 0)
			return ;
		i++;
	}
	ft_wordlow(cmd);
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
	free(new_envp);
}
