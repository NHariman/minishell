/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_get_file_name.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:52:00 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/27 16:47:32 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	rd_get_file_name(t_struct_rd *rd)
{
	char	*name;
	int		j;

	j = 0;
	if (rd->str[rd->i] == '$')
	{
		while (ft_isalnum(rd->str[rd->i + j + 1]) || rd->str[rd->i + j + 1] == '_')
			j++;
		name = ft_substr(rd->str, rd->i, j + 1);
	}
	rd->file = ft_no_quotes_str(rd->str, &rd->i, "<> \n");
	if (ft_strchr(rd->file, ' '))
	{
		ft_printf_err("minishell: %s: ambiguous redirect\n", name);
		free(name);
		rd->error = 1;
		return ;
	}
	free(name);
	rd->error = 0;
}
