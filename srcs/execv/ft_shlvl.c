/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shlvl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 18:30:19 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/06 12:33:47 by nhariman      ########   odam.nl         */
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
	level = ft_atoi(shlvl);
	level = level + 1;
	update_env_shlvl(level);
	free(shlvl);
}
