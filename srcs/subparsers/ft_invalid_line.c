/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_invalid_line.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 19:44:11 by nhariman      #+#    #+#                 */
/*   Updated: 2020/12/05 22:32:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_find_input(char **tmp, char *str, int *i, t_shell *shell)
{
	*tmp = ft_no_quotes_str(str, i, shell, " ;");
	*i = *i + ft_iswhitespaces(str + *i);
	if (str[*i] == ';' && str[*i + ft_iswhitespaces(str + *i + 1)] != '\0')
	{
		*i = *i + 1;
		*tmp = NULL;
		free(*tmp);
	}
}

int			ft_invalid_line(char *str, t_shell *shell, char *token)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i] != '\0')
	{
		i = i + ft_iswhitespaces(str + i);
		if (ft_strchr(token, str[i]) && tmp == NULL)
		{
			shell->exit_code = 258;
			return (ft_printf_err(
			"minishell: syntax error near unexpected token `%c'\n"), str[i]);
		}
		else if (str[i] != ' ' &&
			str[i + 1 + ft_iswhitespaces(str + i + 1)] != '\0' &&
			!ft_strchr(token, str[i]))
			ft_find_input(&tmp, str, &i, shell);
		else
			i++;
	}
	free(tmp);
	return (0);
}
