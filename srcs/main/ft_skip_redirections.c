/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skip_redirections.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:57:25 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/12 23:29:01 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_skip_rd(char *str, int *i)
{
	char	*res;

	while (str[*i] == '>')
		*i = *i + 1;
	while (str[*i] == '<')
		*i = *i + 1;
	while (str[*i] == ' ')
		*i = *i + 1;
	res = ft_no_quotes_str(str, i, " ");
	if (str[*i] != '\0')
		*i = *i + 1;
	free(res);
}
