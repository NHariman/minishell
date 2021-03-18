/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_end.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 11:02:15 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 13:42:57 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// ft_printf("bash: syntax error near unexpected token `<'\n");

#include "../minishell.h"

int		ft_semicol_err()
{
	ft_printf("minishell: syntax error near unexpected token `;'\n");
	shell.exit_code = 1;
	return (1);
}

int		is_token(char c)
{
	if (c == '|' || c == ';' || c == '>' || c == '<')
		return (1);
	return (0);
}


int     check_end(char *line)
{
    int i;

	i = 0;
	if (line[0] == ';')
		return (ft_semicol_err());
	while (line[i] != '\0')
	{
		if (line[i] == ';')
		{
			i = i + ft_iswhitespaces(line + i + 1) + 1;
			if (is_token(line[i]))
				return (ft_semicol_err());
		}
		i++;
	}
	return (0);
}
