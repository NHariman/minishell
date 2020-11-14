/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   re_direct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/11/12 19:36:41 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
	first check for >

	if file is there, chck if its ther,e then jsut put the info in there
	//if file is not there, create and then ut it in
*/

void		start_rd(t_struct_rd *rd, t_shell *shell)
{
	rd->i = 0;
	while (rd->s_str[rd->i] == ' ')
		rd->i++;
	if (ft_strncmp("ECHO", rd->s_str + rd->i++, 3) == 0)
		rd_echo(rd, shell);
}

char		*rd_main(char *str, t_struct_rd *rd, t_shell *shell)
{
	set_value_rd(rd);
	rd->s_str = ft_strdup(str);
	free(str);
	while (rd->s_str[rd->i])
	{
		if (rd->s_str[rd->i] == '>')
		{
			start_rd(rd, shell);
			break ;
		}
		rd->i++;
	}
	str = ft_strdup(rd->s_str);
	free(rd->s_str);
	return (str);
}
