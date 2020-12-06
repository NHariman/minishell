/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pipe_splitter.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 22:09:14 by nhariman      #+#    #+#                 */
/*   Updated: 2020/12/06 17:30:17 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			ft_pipe_splitter(char *str, t_shell *shell)
{
	ft_printf("lol pipes, what's in shell?\n");
	ft_printf("shell->env[0]: %s\n", shell->env[0]);
	// int k = 0;
	// while (shell->env[k] != (char *)0)
	// {
	// 	ft_printf("shell->env[%i]: {%s}\n", k, shell->env[k]);
	// 	k++;
	// }
	ft_printf("and now the string:\n{%s}\n", str);
}