/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skip_redirections.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 20:57:25 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/29 00:33:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void			ft_skip_rd(char *str, int *i)
{
	*i = *i + 1;
	*i = *i + ft_iswhitespaces(str + *i);
	while (str[*i] != ' ' && str[*i] != '\0')
		*i = *i + 1;
	*i = *i + ft_iswhitespaces(str + *i);
}

void			ft_skip_redirections(char *str, int *i, t_trim *trim)
{
	if (trim->res == NULL)
		trim->res = ft_substr(str, trim->start, *i - trim->start);
	*i = *i + 1;
	*i = *i + ft_iswhitespaces(str + *i);
	while (str[*i] != ' ' && str[*i] != '\0')
		*i = *i + 1;
	*i = *i + ft_iswhitespaces(str + *i);
	trim->start = *i;
}
