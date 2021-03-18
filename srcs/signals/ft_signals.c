/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_signals.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:07:26 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/18 11:37:43 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    handle_hangup(int sign)
{
	if (sign == 2)
		sign = 0;
}

void handle_interrupt(int sign)
{
	if (sign == 3)
		sign = 0;
}

void		ft_signals_control(void)
{
	signal(SIGINT, handle_hangup);
	signal(SIGQUIT, handle_interrupt);
	return ;
}