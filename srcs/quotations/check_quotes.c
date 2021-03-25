/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_quotes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 19:43:53 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/25 13:50:49 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tilde_expansion(char *str, int *i, t_trim *trim)
{
	(void)i;
	(void)str;
	(void)trim;
	return ;
}

void	check_quotes(char *str, int *i, t_trim *trim)
{
	if (str[*i] == '\"' && ft_backslash_check(str, *i) % 2 == 0)
		ft_nqts_dq_strjoin(str, i, trim);
	else if (str[*i] == '\'' && ft_backslash_check(str, *i) % 2 == 0)
		ft_nqts_sq_strjoin(str, i, trim);
	else if (str[*i] == '~' && ft_backslash_check(str, *i) % 2 == 0)
		ft_tilde_expansion(str, i, trim);
}
