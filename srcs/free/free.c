/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:15:13 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/25 13:27:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_malloc_fail(void)
{
	ft_printf_err("Error\nMalloc failed. Exiting program.\n");
	exit(1);
}

void	ft_free_array(char **arr, int len)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

static void	ft_free_shell(char *str)
{
	str = NULL;
	free(str);
}

void	ft_clear_shell(void)
{
	g_shell.check.echo = 0;
	g_shell.check.env = 0;
	g_shell.check.exp = 0;
	g_shell.check.exec = 0;
	g_shell.check.err = 0;
	g_shell.check.pwd = 0;
	g_shell.fd = -1;
	g_shell.oldnb = 0;
	if (g_shell.argv != NULL)
		ft_free_array(g_shell.argv, ft_arrlen(g_shell.argv));
	if (g_shell.ret != (char *) 0)
		ft_free_shell(g_shell.ret);
	if (g_shell.echo != (char *) 0)
		ft_free_shell(g_shell.echo);
	if (g_shell.pwd != (char *) 0)
		ft_free_shell(g_shell.pwd);
	if (g_shell.env_s != (char *) 0)
		ft_free_shell(g_shell.env_s);
	if (g_shell.exprt != NULL)
		ft_free_shell(g_shell.exprt);
	if (g_shell.err != (char *) 0)
		ft_free_shell(g_shell.err);
}
