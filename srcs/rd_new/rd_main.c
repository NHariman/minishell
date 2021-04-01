/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:24:14 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 16:26:30 by ybakker       ########   odam.nl         */
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
	rd->str = ft_strtrim(str, "\n");
	rd->file = ft_strdup("");
	printf("string == [%s]\n", rd->str);	
	if (get_check_redirect(rd) > 0)
		g_shell.exit_code = -1;
	else if (rd_loop(rd) > 0)
		g_shell.exit_code = -1;
	free(rd->str);
	free(rd);
}
