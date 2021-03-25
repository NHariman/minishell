/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rd_syntax_error_add.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 15:02:41 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 15:37:30 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	rd_syntax_error(char *line, int i, int len)
{
	if (len == 0)
		return (0);
	if (rd_syntax_error_right(line, i) == -1
			|| rd_syntax_error_left(line, i) == -1)
		return (-1);
	return (0);
}

int	rd_syntax_error_left(char *line, int i)
{
	int len;

	len = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '<')
	{
		while (line[i] == '<')
		{
			len++;
			i++;
		}
	}
	else
		return (0);
	if (len == 1)
		ft_printf("bash: syntax error near unexpected token `<'\n");
	if (len == 2)
		ft_printf("bash: syntax error near unexpected token `<<'\n");
	if (len >= 3)
		ft_printf("bash: syntax error near unexpected token `<<<'\n");
	return (-1);
}

int	rd_syntax_error_right(char *line, int i)
{
	int len;

	len = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '>')
	{
		while (line[i] == '>')
		{
			len++;
			i++;
		}
	}
	else
		return (0);
	if (len >= 1 && len <= 2 )
		ft_printf("bash: syntax error near unexpected token `>'\n");
	else
		ft_printf("bash: syntax error near unexpected token `>>'\n");
	return (-1);
}