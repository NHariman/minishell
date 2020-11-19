/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 21:40:43 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/19 21:41:45 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				ft_qt_rd(char *line, t_qts *qts, int *i)
{
	while (line[*i] != '\0')
	{
		if (ft_strchr("|;<", line[*i]))
			return ;
		else if ((line[*i] == '\'' && line[*i - 1] != '\\') ||
		(line[*i] == '\'' && ft_backslash_check(line, *i) % 2 == 0))
		{
			qts->sq = ft_qt_check(line, i, SQ, qts);
			*i = *i + 1;
		}
		else if ((line[*i] == '\"' && line[*i - 1] != '\\') ||
		(line[*i] == '\"' && ft_backslash_check(line, *i) % 2 == 0))
		{
			qts->dq = ft_qt_check(line, i, DQ, qts);
			*i = *i + 1;
		}
		else
			*i = *i + 1;
	}
}
