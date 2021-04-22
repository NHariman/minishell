/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_directory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 21:54:48 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/23 00:04:12 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_directory(char *cmd)
{
	struct stat	statbuf;
	int			check;

	check = lstat(cmd, &statbuf);
	if (check == -1)
		return (0);
	else if (S_ISDIR(statbuf.st_mode))
	{
		g_shell.exit_code = 126;
		return (ft_printf_err("minishell: %s: is a directory\n",
				g_shell.argv[0]));
	}
	return (0);
}

int	ft_ispath(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
