/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_fill_file.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:42:48 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/12 18:04:41 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static void	rd_one(t_struct_rd *rd)
{
	dup2(rd->fd, 1);
	ft_wordparser();
}

static void	rd_two(t_struct_rd *rd)
{
	dup2(rd->fd_rd, 0);
	ft_wordparser();
}

void	rd_open_file_fill(t_struct_rd *rd)
{
	if (rd->store == 1 || rd->store == 2)
	{
		rd_one(rd);
		if (rd->fd_rd != -1)
			rd_two(rd);
	}
	else if (rd->store == 3)
	{
		rd_two(rd);
		if (rd->fd != -1)
			rd_one(rd);
	}
	if (rd->fd != -1)
	{
		close(1);
		close(rd->fd);
	}
	else if (rd->fd_rd != -1)
	{
		close(0);
		close(rd->fd_rd);
	}
}
