/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shlvl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 18:30:19 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/25 18:42:16 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	update_env_shlvl(int level)
{
	int		i;
	char	*name;
	char	*lvl;
	char	*new_str;

	i = 0;
	lvl = ft_itoa(level);
	new_str = ft_strjointwo("SHLVL=", lvl);
	while (g_shell.env[i])
	{
		name = ft_find_varname(g_shell.env[i]);
		if (ft_strcmp(name, "SHLVL") == 0)
		{
			free(g_shell.env[i]);
			g_shell.env[i] = ft_strdup(new_str);
			free(new_str);
			return ;
		}
		if (name)
			free(name);
		i++;
	}
}

void	increase_shlvl(void)
{
	int		level;
	char	*shlvl;

	shlvl = ft_find_envvar("SHLVL");
	level = ft_atoi(shlvl);
	level = level + 1;
	update_env_shlvl(level);
	free(shlvl);
}
