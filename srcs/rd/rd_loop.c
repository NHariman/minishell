/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:48:53 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/28 19:04:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static int	loop_in(t_struct_rd *rd)
{
	while (rd->str[rd->i] && rd->str[rd->i] != '\0' && rd->error == 0)
	{
		free(rd->file);
		rd->nb = 0;
		rd->error = rd_get_nb(rd);
		if (rd->error > 0)
			return (rd->error);
		if (rd->store == -1)
			rd->store = rd->nb;
		rd_get_file_name(rd);
		if (rd->error != 0)
			return (rd->error);
		if (rd->nb == 1 || rd->nb == 2)
			rd->nb = 0;
		rd_open_file(rd);
	}
	rd->i = 0;
	return (rd->error);
}

int	rd_loop(t_struct_rd *rd, int *new_fds)
{
	rd->i = 0;
	rd->error = 0;
	if (loop_in(rd) == 1)
		return (rd->error);
	while (rd->str[rd->i] && rd->str[rd->i] != '\0' && rd->error == 0)
	{
		free(rd->file);
		rd->nb = 0;
		rd->error = rd_get_nb(rd);
		if (rd->error > 0)
			return (rd->error);
		if (rd->store == -1)
			rd->store = rd->nb;
		rd_get_file_name(rd);
		if (rd->error != 0)
			return (rd->error);
		rd_open_file(rd);
	}
	if (rd->error != 0)
		return (rd->error);
	rd_open_file_fill(rd, new_fds);
	return (rd->error);
}
