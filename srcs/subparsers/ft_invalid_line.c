/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_invalid_line.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 19:44:11 by nhariman      #+#    #+#                 */
/*   Updated: 2020/12/03 22:50:40 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_invalid_line(char *str, t_shell *shell)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	ft_printf("preloop tmp: {%s}\nstr: {%s}\n", tmp, str + i);
	while (str[i] != '\n' && str[i] != '\0')
	{
		i = i + ft_iswhitespaces(str + i);
		if (str[i] == ';' && tmp == NULL)
		{
			return (ft_printf_err(
				"minishell: syntax error near unexpected token `;'\n"));
		}
		if (str[i] != ' ' && str[i] != '\0')
		{
			tmp = ft_no_quotes_str(str, &i, shell, " ;");
			i = i + ft_iswhitespaces(str + i);
			if (str[i] == ';' && str[i + ft_iswhitespaces(str + i)] != '\0')
			{
				i++;
				tmp = NULL;
				free(tmp);
			}
			ft_printf("tmp: {%s}\nstr: {%s}\n", tmp, str + i);
		}
	}
	free(tmp);
	return (0);
}
