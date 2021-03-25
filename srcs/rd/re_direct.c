/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 13:27:07 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	rd_main(char *str)
{
	t_struct_rd	*rd;

	rd = calloc(1, sizeof(t_struct_rd));
	rd->fd = -1;
	rd->fd_rd = -1;
	rd->i = 0;
	rd->error = 0;
	rd_value_rd(rd);
	rd->str = ft_strtrim(str, "\n");
	ft_printf("in == [%s][%i]\n", rd->str, rd->i);
	if (error_check_rd(rd) > 0 || rd_loop(rd) > 0)
	{
		g_shell.exit_code = -1;
	}
}
