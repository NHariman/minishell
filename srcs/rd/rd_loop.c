/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_loop.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 16:07:05 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int	rd_get_nb(t_struct_rd *rd)
{
	while (rd->str[rd->i] == ' ')
		rd->i++;
	if (rd->str[rd->i] != '<' && rd->str[rd->i] != '>')
		return (1);
	else if (rd->str[rd->i] == '<')
	{
		rd->nb = 3;
		while (rd->str[rd->i] == '<' || rd->str[rd->i] == ' ')
			rd->i++;
		return (rd->error);
	}
	else
	{
		if (rd->str[rd->i] == '>')
			rd->nb = 1;
		rd->i++;
		if (rd->str[rd->i] == '>')
		{
			rd->nb = 2;
			rd->i++;
		}
		while (rd->str[rd->i] == ' ')
			rd->i++;
	}
	return (0);
}

int	rd_loop(t_struct_rd *rd)
{
	t_struct_m	*echo;

	echo = ft_calloc(1, sizeof(t_struct_m));
	rd->i = 0;
	rd->error = 0;
	while (rd->str[rd->i] && rd->str[rd->i] != '\n' && rd->error == 0)
	{
		free(rd->tmp);
		rd_value_rd(rd);
		rd->error = rd_get_nb(rd);
		if (rd->error > 0)
		{
			free(echo);
			return (rd->error);
		}
		rd_get_file_name(rd, echo);
		rd_open_file(rd);
		printf("[%s]\n", rd->str);
	}
	free(rd->tmp);
	free(rd->file);
	rd_open_file_fill(rd);
	free(echo);
	free(rd->str);
	return (rd->error);
}
