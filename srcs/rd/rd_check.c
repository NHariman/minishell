/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/23 17:30:54 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int	rd_check_error_out(t_struct_rd *rd)
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
	else if (len == 3)
		ft_printf("bash: syntax error near unexpected token `>'\n");
	else if (len > 3)
		ft_printf("bash: syntax error near unexpected token `>>'\n");
	shell.exit_code = 1;
	return (shell.exit_code);
}

int	rd_check_error_in(t_struct_rd *rd)
{
	int		len;

	len = 0;
	while (rd->str[rd->rdi] == '<')
	{
		rd->rdi++;
		len++;
	}
	if (len == 1)
		return (0);
	else if (len >= 2 && len < 4)
		ft_printf("bash: syntax error near unexpected token `<'\n");
	else if (len == 5)
		ft_printf("bash: syntax error near unexpected token `<<'\n");
	else if (len >= 6)
		ft_printf("bash: syntax error near unexpected token `<<<'\n");
	shell.exit_code = 1;
	return (shell.exit_code);
}

int	error_check_rd(t_struct_rd *rd)
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
		ft_printf("%s\n", ft_no_quotes_str(rd->str, &rd->rdi, "<>"));
	}
	return (0);
}
