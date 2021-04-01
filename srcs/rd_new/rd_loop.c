/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:48:53 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 15:01:57 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int	rd_loop(t_struct_rd *rd)
{
	rd->i = 0;
	rd->error = 0;
	while (rd->str[rd->i] && rd->str[rd->i] != '\n' && rd->error == 0)
	{
		rd->nb = 0;
		rd->error = rd_get_nb(rd);
        printf("nb == [%i]\n", rd->nb);
		if (rd->error > 0)
			return (rd->error);
        
		// rd_get_file(rd);
	}
	rd_open_file_fill(rd);
	return (rd->error);
}