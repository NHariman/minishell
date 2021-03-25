/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_quotes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 19:43:53 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/25 18:06:15 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tilde_expansion(t_trim *trim, int *i, char *str)
{
	if (str[*i] == '~' && (ft_strchr(" /<>", str[*i + 1])
			|| str[*i + 1] == '\0'))
	{
		trim->res = ft_find_envvar("HOME");
		*i = *i + 1;
	}
}

void	check_quotes(char *str, int *i, t_trim *trim)
{
	if (str[*i] == '\"' && ft_backslash_check(str, *i) % 2 == 0)
		ft_nqts_dq_strjoin(str, i, trim);
	else if (str[*i] == '\'' && ft_backslash_check(str, *i) % 2 == 0)
		ft_nqts_sq_strjoin(str, i, trim);
}
