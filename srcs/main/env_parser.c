/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 13:20:43 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/18 17:47:37 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** env $HOME: tries to execute/access $HOME
** env "test=test" creates an environment variable named $test with value test
** env prints a list of current environment variables. [x]
*/

static char	*ft_make_env_str(t_shell *shell)
{
	int		len;
	int		i;
	char	*new_str;
	char	*tmp;

	len = ft_envlen(shell);
	new_str = ft_charjoin(shell->env[0], '\n');
	i = 1;
	while (i < len - 1)
	{
		tmp = gnl_strjoin(new_str, ft_charjoin(shell->env[i], '\n'));
		new_str = tmp;
		i++;
	}
	tmp = gnl_strjoin(new_str, shell->env[i]);
	new_str = tmp;
	return (new_str);
}

void		ft_env_parser(char *str, int *i, t_shell *shell)
{
	char	*env_str;
	int		start;
	int		check;

	start = *i;
	check = 0;
	while (str[*i] != '\n' && str[*i] != '\0' && !ft_strchr("|;", str[*i]))
		*i = *i + 1;
	if (start == *i)
	{
		shell->env_s = ft_make_env_str(shell);
		if (ft_strchr("\n;\0", str[*i]))
			ft_printf("%s\n", shell->env_s);
	}
	else
	{
		env_str = ft_substr(str, start, *i - start);
		check = env_main(env_str, shell);
	}
	if (check > 0)
		shell->exit_code = check;
	else
		shell->exit_code = 0;
}