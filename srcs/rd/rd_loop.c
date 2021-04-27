/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:48:53 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/27 16:45:02 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int	rd_loop(t_struct_rd *rd, int *new_fds)
{
	rd->i = 0;
	rd->error = 0;
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
