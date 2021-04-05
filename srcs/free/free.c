/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:15:13 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/05 13:58:26 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_malloc_fail(char *str)
{
	ft_printf_err("Error\nMalloc failed.\n");
	ft_printf_err("Error occured in: %s\n", str);
	ft_printf_err("Exiting program.\n");
	exit(1);
}

void	ft_clear_shell(void)
{
	g_shell.fd = -1;
	if (g_shell.argv != NULL)
		ft_free_array(g_shell.argv, ft_arrlen(g_shell.argv));
}
