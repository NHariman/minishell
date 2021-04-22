/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/22 23:50:15 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

void	prompt(void)
{
	ft_printf("\033[1;36m");
	ft_printf("minishell> ");
	ft_printf("\033[0m");
}

static void	start_minishell(char **envp)
{
	g_shell.env = ft_arrdup(envp);
	increase_shlvl();
	ft_delete_env("OLDPWD");
	g_shell.exit_code = 0;
	g_shell.child_pid = -2;
	g_shell.tpid = -2;
	g_shell.argv = NULL;
}

void	error_exit(char *str, int nb)
{
	write(2, str, ft_strlen(str));
	exit(nb);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	*line;

	(void)argv;
	i = argc;
	if (argc > 1)
		ft_printf_err("Too many arguments.\n");
	start_minishell(envp);
	while (i == 1)
	{
		prompt();
		ft_signals_control();
		i = get_next_line_sig(0, &line);
		if (i == 0 && !line[0])
		{
			ft_printf("exit\n");
			exit(0);
		}
		ft_make_prompts(line);
		free(line);
	}
	return (0);
}
