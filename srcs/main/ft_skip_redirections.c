/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skip_redirections.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:57:25 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/06 15:28:10 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_skip_rd(char *str, int *i)
{
	char	*res;

	while (str[*i] == '>')
		*i = *i + 1;
	while (str[*i] == ' ')
		*i = *i + 1;
	res = ft_no_quotes_str(str, i, " ");
	*i = *i + 1;
	free(res);
}
