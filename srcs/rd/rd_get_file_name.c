/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_get_file_name.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:52:00 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/08 08:45:36 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

void	rd_get_file_name(t_struct_rd *rd)
{
	if (rd->str[rd->i] == '\0')
		rd->file = ft_strdup("");
	else
		rd->file = ft_no_quotes_str(rd->str, &rd->i, "<> \n");
}
