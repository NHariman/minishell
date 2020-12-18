/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_update_env.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 04:53:31 by nhariman      #+#    #+#                 */
/*   Updated: 2020/12/19 00:06:03 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*ft_find_varname(char *str)
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

static void		ft_update_shell(t_shell *shell, char *str, char *var)
{
	int		i;
	char	*name;

	i = 0;
	name = NULL;
	while (shell->env[i])
	{
		name = ft_find_varname(shell->env[i]);
		if (ft_strcmp(name, var) == 0)
		{
			//free(shell->env[i]);
			shell->env[i] = ft_strdup(str);
			free(str);
			return ;
		}
		i++;
	}
	if (name)
		free(name);
}

void			ft_update_env(t_shell *shell, char *str)
{
	char	*var;
	char	**newenv;

	var = ft_find_varname(str);
	if (ft_find_envvar(var, shell) == NULL)
	{
		newenv = ft_add_arr_back(shell->env, str);
		ft_free_array(shell->env, ft_arrlen(shell->env));
		shell->env = newenv;
	}
	else
		ft_update_shell(shell, str, var);
	free(var);
}