/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shlvl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 18:30:19 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/30 19:08:08 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	update_env_shlvl(int level)
{
	char	*lvl;
	char	*new_str;

	lvl = ft_itoa(level);
	new_str = ft_strjointwo("SHLVL=", lvl);
	ft_update_env(new_str);
	free(new_str);
}

void	increase_shlvl(void)
{
	int		level;
	char	*shlvl;
	shlvl = ft_find_envvar("SHLVL");
	if (!shlvl)
	{
		ft_update_env("SHLVL=1");
		return ;
	}
	level = ft_atoi(shlvl);
	level = level + 1;
	update_env_shlvl(level);
	free(shlvl);
}
