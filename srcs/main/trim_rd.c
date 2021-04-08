/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trim_rd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nhariman <nhariman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 22:48:35 by nhariman      #+#    #+#                 */
/*   Updated: 2021/04/08 23:49:53 by nhariman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	trim_rd_str(char *str, int *i, t_trim *trim)
{
	char	*oldstr;

	oldstr = ft_substr(str, trim->start, trim->start - *i);
	ft_skip_rd(str, i);
	trim->start = *i;
	if (!trim->res)
		trim->res = ft_strdup(oldstr);
	else
		trim->res = gnl_strjoin(trim->res, oldstr);
	free(oldstr);
}

static char	*fill_trim_rd_output(t_trim trim, char *str, int i)
{
	char	*output;
	char	*endstr;

	if (!trim.res)
		output = ft_strdup(str);
	else
	{
		endstr = ft_substr(str, trim.start, trim.start - i);
		if (endstr)
		{
			trim.res = gnl_strjoin(trim.res, endstr);
			free(endstr);
		}
		output = ft_strdup(trim.res);
		free(trim.res);
	}
	return (output);
}

char	*trim_rd(char *line)
{
	t_trim	trim;
	char	*output;
	int		i;

	trim.start = 0;
	trim.res = (char *) 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr("\'\"", line[i]) && ft_backslash_check(line, i) % 2 == 0)
			ft_skip_quotes(line, &i, line[i]);
		else if (line[i] == '<' || line[i] == '>')
			trim_rd_str(line, &i, &trim);
		else
			i++;
	}
	output = fill_trim_rd_output(trim, line, i);
	return (output);
}
