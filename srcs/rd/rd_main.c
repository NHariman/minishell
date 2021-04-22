/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:24:14 by ybakker       #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2021/04/15 19:52:13 by nhariman      ########   odam.nl         */
=======
/*   Updated: 2021/04/16 13:05:00 by ybakker       ########   odam.nl         */
>>>>>>> 06b726ef015b187d248b356a0e1ec19d99f6b74d
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int	rd_main(char *str, int *new_fds)
{
	t_struct_rd	*rd;
	int			ret;

	rd = calloc(1, sizeof(t_struct_rd));
	rd->out = -1;
	rd->in = -1;
	rd->i = 0;
	rd->error = 0;
	rd->str = ft_strtrim(str, "\n");
	rd->file = ft_strdup("");
	rd->store = -1;
	if (get_check_redirect(rd) == 0)
		rd_loop(rd, new_fds);
	ret = rd->error;
	free(rd->str);
	free(rd->file);
	free(str);
	free(rd);
	return (ret);

}
