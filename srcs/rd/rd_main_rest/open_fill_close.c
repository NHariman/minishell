/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_fill_close.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 17:47:45 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/28 17:09:01 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int		open_fill_close_file(char *file, char *string,
int nb, t_shell *shell)
{
	int		fd;

	fd = 0;
	errno = 0;
	ft_printf("open fill closee [%i]\n", nb);
	if (nb == 3)
	{
		nb = shell->oldnb;
		shell->fd = open(file, O_RDWR);
		ft_printf("file == [%s]\n", file);
		if (shell->fd < 0)
		{
			ft_printf_err("Error\n%s\n", strerror(errno));
			shell->exit_code = 1;
			return (1);
		}
		else
		{
			redirect_file(shell->fd, shell);
			close(shell->fd);
		}
		return (0);
	}
	else
	{
		if (nb == 1)
			shell->fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0666);
		else if (nb == 2)
			shell->fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0666);
		if (shell->fd < 0)
		{
			ft_printf_err("Error\n%s\n", strerror(errno));
			shell->exit_code = 1;
			return (1);
		}
		write(shell->fd, string, ft_strlen(string));
		write(shell->fd, "\n", 1);
		return (0);
		nb = 0;
	}
	// if (shell->check.shell == 1)
	// {
	// 	dup2(fd, 255);
	//	dup(fd, 1);
	// 	//shell;
	// 	close(fd);
	// }
	close(shell->fd);//if shell is on, do this after shell is done
	return (0);
}
