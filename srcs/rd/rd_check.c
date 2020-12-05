/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 15:28:15 by ybakker       #+#    #+#                 */
/*   Updated: 2020/12/03 17:52:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

/*
check > > >
if no file inbetween, then fail
check >>>>
check <<<<
*/

int				rd_check_error_out(t_struct_rd *rd, t_shell *shell)
{
	int		len;

	len = 0;
	while (rd->str[rd->rdi] == '>')
	{
		rd->rdi++;
		len++;
	}
	if (len == 1)
		return (0);
	else if (len == 2)
		ft_printf("bash: syntax error near unexpected token `>'\n");
	else if (len > 2)
		ft_printf("bash: syntax error near unexpected token `>>'\n");
	shell->exit_code = 1;
	return (shell->exit_code = 1);
}

int				rd_check_error_in(t_struct_rd *rd, t_shell *shell)
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
	shell->exit_code = 1;
	return (shell->exit_code = 1);
}

int		error_check_rd(t_struct_rd *rd, t_shell *shell)
{
	// printf("[%s]string\n", rd->str);
	// rd->rdi++;
	// while (rd->str[rd->rdi] == ' ')
	// 	rd->rdi++;
	// ft_printf("%s\n", rd->str + rd->rdi, shell);
	// ft_printf("no quotes %s\n", ft_no_quotes_str(rd->str, &rd->rdi, shell, "<>"));
	while (rd->str[rd->rdi] || rd->str[rd->rdi] != '\0')
	{
		if (rd->str[rd->rdi] == '>')
		{
			if (rd_check_error_out(rd, shell) > 0)
				return (1);
		}
		else if (rd->str[rd->rdi] == '<')
		{
			if (rd_check_error_in(rd, shell))
				return (1);
		}
		rd->rdi++;
		while (rd->str[rd->rdi] == ' ')
			rd->rdi++;
		ft_printf("%s\n", ft_no_quotes_str(rd->str, &rd->rdi, shell, "<>"));
	}
	return (0);
}
