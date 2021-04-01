/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_redirect.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 14:26:17 by ybakker       #+#    #+#                 */
/*   Updated: 2021/04/01 14:39:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

static int	rd_check_error_out(t_struct_rd *rd)
{
	int		len;

	len = 0;
	while (rd->str[rd->rdi] == '>')
	{
		rd->rdi++;
		len++;
	}
	if (len == 1 || len == 2)
		return (0);
	return (1);
}

static int	rd_check_error_in(t_struct_rd *rd)
{
	int		len;

	len = 0;
	while (rd->str[rd->rdi] == '<')
	{
		rd->rdi++;
		len++;
		while (rd->str[rd->rdi] == ' ')
			rd->rdi++;
	}
	rd->rdi--;
	if (len == 1 || len == 3)
		return (0);
	return (1);
}

int	get_check_redirect(t_struct_rd *rd)
{
	rd->rdi = rd->i;
	while (rd->str[rd->rdi] || rd->str[rd->rdi] != '\0')
	{
		if (rd->str[rd->rdi] == '\\')
		{
			if (rd_check_error_out(rd) > 0)
				return (1);
		}
		else if (rd->str[rd->rdi] == '>')
		{
			if (rd_check_error_out(rd) > 0)
				return (1);
		}
		else if (rd->str[rd->rdi] == '<')
		{
			if (rd_check_error_in(rd))
				return (1);
		}
		rd->rdi++;
		while (rd->str[rd->rdi] == ' ')
			rd->rdi++;
	}
	return (0);
}
