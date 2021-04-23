/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dollar_sign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 19:40:08 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/23 23:08:46 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*return_exitcode(char *var)
{
	char	*exit;

	exit = ft_itoa(g_shell.exit_code);
	free(var);
	return (exit);
}

static char	*ft_find_env_variable(char *var)
{
	char	*env_var;
	int		i;
	char	*tmp;

	i = 0;
	if (var == NULL)
		return (NULL);
	if (!ft_strncmp(var, "?", ft_strlen(var)))
		return (return_exitcode(var));
	tmp = gnl_strjoin(var, "=");
	while (g_shell.env[i] != NULL)
	{
		if (!ft_strncmp(g_shell.env[i], tmp, ft_strlen(tmp)))
		{
			env_var = ft_substr(g_shell.env[i], ft_strlen(tmp),
					ft_strlen(g_shell.env[i]));
			free(tmp);
			return (env_var);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

static char	*ft_get_var(char *str, int *i)
{
	char	*var;
	int		start;

	start = *i;
	if (!str[start])
		return (NULL);
	while (ft_isalpha(str[*i]) || str[*i] == '_')
		*i = *i + 1;
	var = ft_substr(str, start, *i - start);
	return (var);
}

char	*ft_find_variable(char *str, int *i)
{
	char	*var;
	char	*output;

	*i = *i + 1;
	var = NULL;
	if (ft_isdigit(str[*i])
		|| (ft_isspecial(str[*i]) && !ft_strchr("\\\'\"!*#-0", str[*i])))
	{
		var = ft_make_single_char_str(str[*i]);
		*i = *i + 1;
	}
	else if (ft_strchr("!*#-0", str[*i]))
	{
		var = NULL;
		ft_printf_err("Minishell does not support");
		ft_printf_err(" special parameters */@/#/-/$/0, undefined behaviour may occur.\n");
	}
	else if (ft_isalpha(str[*i]))
		var = ft_get_var(str, i);
	output = ft_find_env_variable(var);
	if (output == NULL)
		output = ft_strdup("");
	return (output);
}

char	*ft_find_envvar(char *var)
{
	char	*env_var;
	int		i;
	char	*tmp;

	i = 0;
	if (var == NULL)
		return (NULL);
	tmp = ft_strjoin(var, "=");
	while (g_shell.env[i] != (char *) 0)
	{
		if (!ft_strncmp(g_shell.env[i], tmp, ft_strlen(tmp))
			|| !ft_strncmp(g_shell.env[i], var, ft_strlen(var)))
		{
			env_var = ft_substr(g_shell.env[i], ft_strlen(tmp),
					ft_strlen(g_shell.env[i]));
			free(tmp);
			return (env_var);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}
