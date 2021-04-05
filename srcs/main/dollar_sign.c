/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dollar_sign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 19:40:08 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/05 15:00:51 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_find_env_variable(char *var)
{
	char	*env_var;
	int		i;
	char	*tmp;

	i = 0;
	if (var == NULL)
		return (NULL);
	if (!ft_strncmp(var, "?", ft_strlen(var)))
		return (ft_itoa(g_shell.exit_code));
	tmp = gnl_strjoin(var, "=");
	while (g_shell.env[i])
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
	while ((!ft_isspecial(str[*i]) || str[*i] != '_')
		&& str[*i] != ' ' && str[*i] != '\0' && str[*i] != '\"')
		*i = *i + 1;
	var = ft_substr(str, start, *i - start);
	return (var);
}

char	*ft_find_variable(char *str, int *i)
{
	int		start;
	char	*var;
	char	*output;

	start = *i + 1;
	*i = *i + 1;
	var = NULL;
	if (ft_isdigit(str[*i])
		|| (ft_isspecial(str[*i]) && !ft_strchr("\\\'\"", str[*i])))
	{
		var = ft_make_single_char_str(str[*i]);
		*i = *i + 1;
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
