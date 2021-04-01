/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:27:27 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/01 18:14:41 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**ft_delete_arr_entry(char **arr, char *var)
{
	int		i;
	int		j;
	int		len;
	char	*env;
	char	**newenv;

	i = 0;
	j = 0;
	len = ft_arrlen(arr);
	newenv = (char **)malloc(sizeof(char *) * len);
	if (!newenv)
		ft_malloc_fail("ft_delete_arr_entry");
	newenv[len - 1] = (char *) 0;
	while (arr[i])
	{
		env = ft_find_varname(arr[i]);
		if (ft_strcmp(env, var) != 0)
		{
			newenv[j] = ft_strdup(arr[i]);
			j++;
		}
		free(env);
		i++;
	}
	return (newenv);
}

static void	ft_delete_env(char *input)
{
	char	**newenvp;

	newenvp = ft_delete_arr_entry(g_shell.env, input);
	ft_free_array(g_shell.env, ft_arrlen(g_shell.env));
	g_shell.env = newenvp;
}

static void	ft_remove_env(char **argv)
{
	int		i;
	char	*envvar;

	i = 1;
	envvar = NULL;
	while (argv[i] != (char *) 0)
	{
		envvar = ft_find_envvar(argv[i]);
		if (ft_valid_envvar(argv[i]) == -1)
		{
			ft_printf_err(
				"minishell: unset: `%s': not a valid identifier\n", argv[i]);
		}
		else if (envvar != NULL)
			ft_delete_env(argv[i]);
		if (envvar)
			free(envvar);
		i++;
	}
}

void	ft_unset(void)
{
	if (ft_arrlen(g_shell.argv) == 1)
		return ;
	ft_remove_env(g_shell.argv);
	g_shell.exit_code = 0;
	return ;
}
