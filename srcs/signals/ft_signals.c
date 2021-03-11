/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_signals.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/11 14:41:11 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    handle_hangup(int sign)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;

	tpid = 0;
	child_pid = fork();
	sign = 0;
	ft_printf("pause\n");
	if (child_pid == 0)
	{
		sign = 0;
		exit(0);
	}
	else
	{
		signal(SIGINT, handle_hangup);
		signal(SIGQUIT, handle_interrupt);
		while(tpid != child_pid)
		{
			tpid = wait(&child_status);	
		}
	}
 //hangup is done by making another fork and wait until hangup is done agian, then go back
  //meaning you make another singals call. this time when you hang up, you go back again
  //interrupt is double. you stop the entire program
}

void handle_interrupt(int sign)
{
//stopping the program
	ft_printf("exit\n");
	sign = 0;
    kill(2);
}

void handle_interrupt_two(int sign)
{
	main_child_process(&shell, i, envp);
	kill(2);
}