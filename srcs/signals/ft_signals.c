/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_signals.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 13:27:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_signals(int sign)
{
	write(1, "\b\b  ", 4);
	if (sign == 2)
	{
		write(1, "\n", 1);
		prompt();
		g_shell.exit_code = 1;
	}
	else if (sign == 3)
		write(1, "\b\b", 2);
}

void	ignore_signal(int sign)
{
	(void)sign;
	write(1, "\n", 1);
}

void	ft_signals_control(void)
{
	signal(SIGINT, handle_signals);
	signal(SIGQUIT, handle_signals);
	return ;
}
