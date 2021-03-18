/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/18 11:29:17 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/minishell.h"
#include <stdio.h>

char	**ft_arrdup(char **arr)
{
	int		len;
	char	**newarr;
	int		i;

	i = 0;
	len = ft_arrlen(arr);
	newarr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!newarr)
		ft_malloc_fail();
	while (arr[i] != (char *)0)
	{
		newarr[i] = ft_strdup(arr[i]);
		i++;
	}
	newarr[i] = (char *)0;
	return (newarr);
}

int		main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	*line;
	char	**hold;
	t_shell	shell;

	i = argc;
	hold = argv;
	if (argc > 1)
		ft_printf_err("Too many arguments.\n");
	shell.env = ft_arrdup(envp);
	shell.exit_code = 0;
	shell.ctrlc = 0;
	while (i == 1)
	{
		ft_printf("\033[1;36m");
		ft_printf("minishell> ");
		ft_printf("\033[0m");
		ft_signals_control();
		i = get_next_line(0, &line);
		if (i == 0)
		{
			ft_printf("exit\n");
			exit(0);
		}
		minishell_parser(line, &shell);
		free(line);
	}
	return (0);
}
