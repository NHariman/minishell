/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 21:15:13 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/01 17:04:16 by nhariman      ########   odam.nl         */
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
	if (!arr || arr[0] == (char *) 0)
		return ;
	while (i < len)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	if (arr)
		free(arr);
	arr = NULL;
}

void	ft_clear_shell(void)
{
	g_shell.fd = -1;
	if (g_shell.argv != NULL)
		ft_free_array(g_shell.argv, ft_arrlen(g_shell.argv));
}
