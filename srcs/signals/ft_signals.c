/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_signals.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/11 12:36:09 by ybakker       ########   odam.nl         */
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
	if (child_pid == 0)
	{
		signal(SIGHUP, handle_hangup);
		// exit(tpid, SIGINT);
		signal(SIGINT, handle_interrupt);
		// kill(tpid, SIGQUIT);
		// signal(SIGQUIT, handle_quitp);
		while(tpid != child_pid)
		{
			tpid = wait(&child_status);	
		}
	}
	else
	{
		signal(SIGHUP, handle_hangup);
		// exit(tpid, SIGINT);
		signal(SIGINT, handle_interrupt);
		// kill(tpid, SIGQUIT);
		// signal(SIGQUIT, handle_quitp);
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
	sign = 0;
    exit(0);
}

void handle_quitp(int sign)
{
	pid_t	child_pid;
	pid_t	tpid;
	int		child_status;

	tpid = 0;
	child_pid = fork();
	sign = 0;
	if (child_pid == 0)
	{
		ft_printf("kill process\n");
		kill(tpid, SIGKILL);
		while(tpid != child_pid)
		{
			tpid = wait(&child_status);	
		}
	}
	else
	{
		ft_printf("kill process2\n");
		kill(tpid, SIGKILL);
		while(tpid != child_pid)
		{
			tpid = wait(&child_status);	
		}
	}
}
