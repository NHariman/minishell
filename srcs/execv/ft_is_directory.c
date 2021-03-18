/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_directory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 21:54:48 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 13:16:34 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_is_directory(char *cmd)
{
	struct stat	statbuf;
	int			check;

	check = lstat(cmd, &statbuf);
	if (S_ISDIR(statbuf.st_mode))
	{
		shell.exit_code = 126;
		return (ft_printf_err("minishell: %s: is a directory\n", shell.argv[0]));
	}
	return (0);
}