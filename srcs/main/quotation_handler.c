/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotation_handler.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 20:28:01 by nhariman      #+#    #+#                 */
/*   Updated: 2020/11/11 01:22:01 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				ft_set_qts(t_qts *qts)
{
	qts->dq = 0;
	qts->sq = 0;
}

static int			ft_qt_check(char *line, int *i, int type, t_qts *qts)
{
	ft_set_qts(qts);
	*i = *i + 1;
	while (line[*i] != '\0' && line[*i] != '\n')
	{
		if ((line[*i] == '\'' && type == SQ) ||
		((line[*i] == '\"' && line[*i - 1] != '\\' && type == DQ) ||
		(line[*i] == '\"' && line[*i - 1] == '\\' &&
		line[*i - 2] == '\\' && type == DQ)))
			return (0);
		*i = *i + 1;
	}
	return (1);
}

void				ft_qt_line(char *line, t_qts *qts, int *i)
{
	while (line[*i] != '\0')
	{
		if (ft_strchr(">|;<", line[*i]))
			return ;
		else if (line[*i] == '\'' && line[*i - 1] != '\\')
			qts->sq = ft_qt_check(line, i, SQ, qts);
		else if (line[*i] == '\"')
			qts->dq = ft_qt_check(line, i, DQ, qts);
		*i = *i + 1;
	}
}

void				ft_qt_start(char *line, t_qts *qts)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == '\'' && line[i - 1] != '\\') ||
		(line[i] == '\'' && line[i - 1] == '\\' && line[i - 2] == '\\'))
			qts->sq = ft_qt_check(line, &i, SQ, qts);
		else if ((line[i] == '\"' && line[i - 1] != '\\') ||
		(line[i] == '\"' && line[i - 1] == '\\' && line[i - 2] == '\\'))
			qts->dq = ft_qt_check(line, &i, DQ, qts);
		i++;
	}
}
