/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_red.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 12:26:27 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 12:55:20 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	check_red_1_while(int i, int len, char *line)
{
	while (line[i])
	{
		if (line[i] == '>')
		{
			while (line[i] == '>')
			{
				len++;
				i++;
			}
			if (len == 3)
			{
				ft_printf("bash: syntax error near unexpected token `>'\n");
				shell.exit_code = 1;
				return (-1);
			}
			else if (len > 3)
			{
				ft_printf("bash: syntax error near unexpected token `>>'\n");
				shell.exit_code = 1;
				return (-1);
			}
		}
		i++;
		len = 0;
	}
	return (0);
}

int	check_red_1(char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	i = check_red_1_while(i, len, line);
	if (i == -1)
	{
		return (-1);
	}
	return (0);
}

static	int	check_red_2_error(int len)
{
	if (len == 1)
		return (-1);
	else if (len > 2 && len < 4)
		ft_printf("bash: syntax error near unexpected token `<'\n");
	else if (len == 5)
		ft_printf("bash: syntax error near unexpected token `<<'\n");
	else if (len >= 6)
		ft_printf("bash: syntax error near unexpected token `<<<'\n");
	shell.exit_code = 1;
	return (0);
}

int	check_red_2(char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '<')
		{
			while (line[i] == '<')
			{
				len++;
				i++;
			}
			if (check_red_2_error(len) == -1)
				return (-1);
			return (-1);
		}
		i++;
		len = 0;
	}
	return (0);
}
