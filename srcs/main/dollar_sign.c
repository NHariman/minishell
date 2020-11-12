/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dollar_sign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 19:40:08 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/12 20:40:11 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*ft_find_env_variable(char *var, t_shell *shell)
{
	char	*env_var;
	int		i;
	char	*tmp;

	i = 0;
	tmp = gnl_strjoin(var, "=");
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], tmp, ft_strlen(tmp)))
		{
			env_var = ft_substr(shell->env[i], ft_strlen(tmp) + 1,
									ft_strlen(shell->env[i]));
			return (env_var);
		}
		i++;
	}
	return (NULL);
}

char	*ft_find_variable(char *str, int *i, t_shell *shell)
{
	int		start;
	char	*var;
	char	*output;

	start = *i + 1;
	*i = *i + 1;
	while (ft_isalpha(str[*i]) || str[*i] == '_')
		*i = *i + 1;
	var = ft_substr(str, start, *i - start);
	output = ft_find_env_variable(var, shell);
	if (output == NULL)
		output = ft_strdup("");
	return (output);
}
