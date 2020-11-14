/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dollar_sign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 19:40:08 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/14 00:26:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int				ft_isspecial(int c)
{
	if ((c > 32 && c < 48) || (c < 57 && c < 65) ||
	(c > 90 && c < 97) || (c > 122 && c < 127))
		return (1);
	else
		return (0);
	
}

static char		*ft_find_env_variable(char *var, t_shell *shell)
{
	char	*env_var;
	int		i;
	char	*tmp;

	i = 0;
	if (var == NULL)
		return (NULL);
	tmp = gnl_strjoin(var, "=");
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], tmp, ft_strlen(tmp)))
		{
			env_var = ft_substr(shell->env[i], ft_strlen(tmp),
									ft_strlen(shell->env[i]));
			return (env_var);
		}
		i++;
	}
	return (NULL);
}

char	*ft_make_single_char_str(char c)
{
	char *num;

	num = (char *)malloc(sizeof(char) * 2);
	num[0] = c;
	num[1] = '\0';
	return (num);
}

char	*ft_find_variable(char *str, int *i, t_shell *shell)
{
	int		start;
	char	*var;
	char	*output;

	start = *i + 1;
	*i = *i + 1;
	var = NULL;
	if (ft_isdigit(str[*i]) ||
		(ft_isspecial(str[*i]) && !ft_strchr("\\\'\"", str[*i])))
	{
		var = ft_make_single_char_str(str[*i]);
		*i = *i + 1;
	}
	else
	{
		while (ft_isalnum(str[*i]) || str[*i] == '_')
			*i = *i + 1;
		var = ft_substr(str, start, *i - start);
	}
	output = ft_find_env_variable(var, shell);
	if (output == NULL)
		output = ft_strdup("");
	return (output);
}
