/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_quotes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/18 19:43:53 by nhariman      #+#    #+#                 */
/*   Updated: 2021/03/18 19:57:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_quotes(char *str, int *i, t_trim *trim)
{
	if (str[*i] == '\"' && ft_backslash_check(str, *i) % 2 == 0)
		ft_nqts_dq_strjoin(str, i, trim);
	else if (str[*i] == '\'' && ft_backslash_check(str, *i) % 2 == 0)
		ft_nqts_sq_strjoin(str, i, trim);
}
