/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 17:45:23 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/29 12:48:25 by nhariman      ########   odam.nl         */
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

static void	print_env(void)
{
	int		i;
	char	*output;

	if (!g_shell.env)
		return ;
	i = 0;
	while (g_shell.env[i] != (char *) 0)
	{
		if (ft_strchr(g_shell.env[i], '='))
		{
			output = ft_charjoin(g_shell.env[i], '\n');
			ft_putstr_fd(output, 1);
			free(output);
		}
		i++;
	}
	return ;
}

void	ft_env(void)
{
	if (ft_arrlen(g_shell.argv) == 1)
	{
		print_env();
		g_shell.exit_code = 0;
	}
	else
	{
		ft_printf_err("minishell: env: too many arguments.\n");
		g_shell.exit_code = 1;
	}
	return ;
}
