/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 23:27:53 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 18:41:19 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_make_export_str(char **env)
{
	int		*order;
	char	*export_str;

	order = ft_order_env(env);
	ft_sort_env(order, env, 1);
	export_str = ft_parse_env_str(order, env);
	free(order);
	return (export_str);
}

int	ft_valid_envvar(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '=')
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isspecial(str[i]) && str[i] != '_'
			&& str[i] != '=' && str[i] != ' ')
			return (-1);
		else if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_add_to_env(void)
{
	int		i;
	int		valid;

	i = 1;
	while (shell.argv[i] != (char *) 0)
	{
		valid = ft_valid_envvar(shell.argv[i]);
		if (valid == 1 || valid == 0)
			ft_update_env(shell.argv[i]);
		else if (valid == -1)
		{
			ft_printf_err(
				"minishell: export: `%s': not a valid identifier\n",
				shell.argv[i]);
			shell.exit_code = 1;
		}
		i++;
	}
}

void	ft_export(void)
{
	shell.exit_code = 0;
	if (ft_arrlen(shell.argv) == 1)
	{
		shell.ret = ft_make_export_str(shell.env);
		ft_printf("%s\n", shell.ret);
		free(shell.ret);
	}
	else
		ft_add_to_env();
}
