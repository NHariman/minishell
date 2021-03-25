/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_update_env.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 04:53:31 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/25 13:27:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_find_varname(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (str[i] == '\0')
		name = ft_strdup(str);
	else
		name = ft_substr(str, 0, i);
	return (name);
}

static void	ft_update_shell(char *str, char *var)
{
	int		i;
	char	*name;

	i = 0;
	name = NULL;
	while (g_shell.env[i])
	{
		name = ft_find_varname(g_shell.env[i]);
		if (ft_strcmp(name, var) == 0)
		{
			free(g_shell.env[i]);
			g_shell.env[i] = ft_strdup(str);
			free(name);
			return ;
		}
		if (name)
			free(name);
		i++;
	}
}

void	ft_update_env(char *str)
{
	char	*var;
	char	**newenv;
	char	*findenv;

	var = ft_find_varname(str);
	findenv = ft_find_envvar(var);
	if (findenv == NULL)
	{
		newenv = ft_add_arr_back(g_shell.env, str);
		ft_free_array(g_shell.env, ft_arrlen(g_shell.env));
		g_shell.env = newenv;
	}
	else
		ft_update_shell(str, var);
	if (findenv)
		free(findenv);
	free(var);
}
