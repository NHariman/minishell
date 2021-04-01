/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 17:45:23 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/01 16:54:06 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** first argument is executable
** every other argument thereafter is part of an argv that should be passed
** into the executable.
** use execv, this will return 0 if succesful, and -1 if error.
** g_shell.exit_err set to 126 for unable to execute. (unless you use a fork?)
*/

/*
** make a linked list of args if the first arg does not contain an = for
** VARIABLE=CONENT
** and execute the command while giving the envp and argv list, if
** that is the only command out there. If not, store it and wait for
** the redirection or pipe.
*/

static char	*ft_make_env_str(void)
{
	int		i;
	char	*new_str;
	char	*tmp;
	char	*output;

	if (!g_shell.env)
		return (NULL);
	new_str = ft_charjoin(g_shell.env[0], '\n');
	i = 1;
	while (g_shell.env[i] != (char *) 0)
	{
		output = ft_charjoin(g_shell.env[i], '\n');
		tmp = gnl_strjoin(new_str, output);
		free(output);
		new_str = tmp;
		i++;
	}
	return (new_str);
}

void	ft_env(void)
{
	char	*tmp;

	if (ft_arrlen(g_shell.argv) == 1)
	{
		tmp = ft_make_env_str();
		if (tmp)
		{
			ft_printf("%s", tmp);
			free(tmp);
		}
		g_shell.exit_code = 0;
	}
	else
	{
		ft_printf_err("minishell: env: too many arguments.\n");
		g_shell.exit_code = 1;
	}
	return ;
}
