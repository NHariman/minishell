/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 08:12:33 by ybakker       #+#    #+#                 */
/*   Updated: 2021/03/25 12:26:40 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_bs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\\')
		{
			ft_printf("minishell: syntax error near unexpected token '\'\n");
			shell.exit_code = 1;
			return (-1);
		}
		i++;
	}
	return (0);
}

int	syntax_check(char *line)
{
	if (check_end(line) || check_red_1(line)
		|| check_red_2(line) || check_bs(line))
	{
		ft_printf("an error has occured\n");
		return (shell.exit_code);
	}
	return (0);
}
