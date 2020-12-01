/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/12/01 15:35:20 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void		rd_main(char *str, t_shell *shell)
{
	t_struct_rd		*rd;

	rd = calloc(1, sizeof(t_struct_rd));
	rd->fd = -1;
	rd->fd_rd = -1;
	rd->i = 0;
	rd->error = 0;
	rd_value_rd(rd);
	rd->str = ft_strtrim(str, "\n");
	free(str);
	ft_printf("in == [%s][%i]\n", rd->str, rd->i);
	if (rd_check_error_rd(rd, shell) > 0 || rd_loop(rd, shell) > 0)
	{
		shell->exit_code = -1;
		//if error, what happens here
	}
}
