/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/11 14:41:59 by ybakker       ########   odam.nl         */
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

// static void		main_start(t_shell *shell, int i, char *envp[])
// {
// 	char	*line;

// 	shell->env = ft_arrdup(envp);
// 	shell->exit_code = 0;
// 	while (i == 1)
// 	{
// 		ft_printf("\033[1;36m");
// 		ft_printf("minishell> ");
// 		ft_printf("\033[0m");
// 		i = get_next_line(0, &line);
// 		minishell_parser(line, shell);
// 		free(line);
// 	}
// }

// static void		main_child_process(t_shell *shell, int i, char *envp[])
// {
// 	pid_t	child_pid;
// 	pid_t	tpid;
// 	int		child_status;
// 	tpid = 0;
// 	child_pid = fork();
// 	if(child_pid == 0)
// 	{
// 		main_start(&shell, i, envp);
// 		exit(1);
// 	}
// 	else
// 	{
// 		signal(SIGQUIT, handle_interrupt);
// 		while(tpid != child_pid)
// 		{
// 			tpid = wait(&child_status);	
// 		}
// 	}
// }
	
// int		main(int argc, char *argv[], char *envp[])
// {
// 	pid_t	child_pid;
// 	pid_t	tpid;
// 	int		child_status;
// 	int		i;
// 	char	**hold;
// 	char	**store = NULL;
// 	t_shell	shell;
	
// 	i = argc;
// 	hold = argv;
// 	if (argc > 1)
// 		ft_printf_err("Too many arguments.\n");
// 	tpid = 0;
// 	child_pid = fork();
// 	if(child_pid == 0)
// 	{
// 		main_child_process(&shell, i, envp);
// 		kill(2);
// 	}
// 	else
// 	{
// 		signal(SIGINT, handle_hangup);
// 		signal(SIGQUIT, handle_interrupt_two);//backslash
// 		if (get_next_line(0, store) == 0)
// 		{
// 			signal(SIGINT, handle_hangup);
// 		}
// 		while(tpid != child_pid)
// 		{
// 			tpid = wait(&child_status);	
// 		}
// 	}
// 	return (0);
// }

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
	signal(SIGINT, handle_hangup);
	signal(SIGQUIT, handle_interrupt);
	if (get_next_line(0, store) == 0)
	{
		signal(SIGINT, handle_hangup);
	}
	while (i == 1)
	{
		ft_printf("\033[1;36m");
		ft_printf("minishell> ");
		ft_printf("\033[0m");
		i = get_next_line(0, &line);
		minishell_parser(line, &shell);
		free(line);
	}
	return (0);
}
