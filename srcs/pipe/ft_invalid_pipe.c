/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_invalid_pipe.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 00:26:40 by nhariman      #+#    #+#                 */
/*   Updated: 2020/12/06 03:37:19 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		ft_skip_cmd(int *check, char *str, int *i, t_shell *shell)
{

}

int				ft_invalid_pipe(char *str, t_shell *shell)
{
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		i = i + ft_iswhitespaces(str + i + 1);
		if (str[i] == '|' && check == -1)
		{
			shell->exit_code = 258;
			return (ft_printf_err(
			"minishell: syntax error near unexpected token `|'\n"));
		}
		else if (str[i] != ' ' &&
			str[i + 1 + ft_iswhitespaces(str + i + 1)] != '\0' &&
			str[i] != '|')
			ft_skip_cmd(&check, str, &i, shell);
		else
			i++;
	}
	return (0);
}